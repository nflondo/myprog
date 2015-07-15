#!/usr/bin/perl
#--------------------------------------------------------------------------------------------------------
# Overview: This script creates/deletes LVM volumes; and runs virt-install for unattended VM installs
#--------------------------------------------------------------------------------------------------------
use warnings;
use strict;

#Display total vcpus, memory, and existing volumes
print "---------------------------------------------------\n";
my $vcpus = `lscpu --extended=CPU | grep ^[0-9] | wc -l`;
print "vCPUS: $vcpus";

# The tr -s '' gets rid of repeat white space and makes it into one white space so cut -d can separate based on one space
my $sysmem = `cat /proc/meminfo | grep MemTotal | tr -s ' ' | cut -d ' ' -f2`;
my $sysmem_mg = $sysmem/1024;
printf "Mem: %2d MB\n",$sysmem_mg;
print "---------------------------------------------------\n";

print `lvs`;

my $num_lv = `lvs | wc -l`; 
if ($num_lv >= 2){
 while (1){
	print "Delete any LVs? ";
	chomp(my $lv_stdin = <STDIN>);
    		if ($lv_stdin =~ /y/i){
			print "Name of LV to delete: ";
			chomp(my $lvdel_stdin = <STDIN>);
			#Figure out mount point and unmount it and remove from fstab
			my $mpoint = `cat /etc/fstab | grep $lvdel_stdin | awk '{print \$2}'`;
			#print "mpoint: $mpoint\n";
			if ($mpoint ne ""){
                unless (system "umount $mpoint"){
                 print "SUCCESS - unmounting LV\n";                
                }else{
                    print "Error unmounting LV\n";
                }
                my $infstab = `cat /etc/fstab | grep -e "$lvdel_stdin"`;
                if ($infstab ne ""){
                    unless (system "sed -i '/'$lvdel_stdin'/d' /etc/fstab"){
                      print "SUCCESS - Deleting LV from /etc/fstab\n";              
                    }else{
                        print "Error Deleting LV from /etc/fstab\n";
                    }
                }#if infstab
            } #if mpoint
            
            
            #Remove LV
            my $lvdel = `lvs -o lv_path | grep $lvdel_stdin`; 
             #print "lvdel: $lvdel\n";
            unless (system "lvremove -f $lvdel"){
                print "SUCCESS - Removing: $lvdel\n";       
            }else{
                print "ERROR removing LV\n";
            }
              
        
        } #if           
        else{
            print "Chose not to delete LVs.  Continuing...\n";
            last;
        }

        

    }#while loop
}#if
else{
    print "FYI - No LVs found\n";
}

while (1){
	print "  Create any LVs? ";
	chomp(my $lv_create = <STDIN>);
    	if ($lv_create =~ /y/i){
			print "Size of LVs (GB): ";
			chomp(my $lv_size = <STDIN>);
            print "Number of LVs: ";
			chomp(my $lv_amount = <STDIN>);
                 for(my $i=1; $i<=$lv_amount; $i++){
                    #print "Will create: lvcreate -L ${lv_size}G -n lv$i lsys";
                 unless (system "lvcreate -L ${lv_size}G -n lv$i lsys"){
                        print "SUCCESS - Creating lv$i\n";                    
                    }else{
                        print "ERROR - Creating lv$i\n";
                        }
                }#for 	


		}
        else{
                print "Chose not to create LVs. Continuing...\n";
            last;
        }

 }

#Now to install VMs
my ($hyper,$tc_ip, $install_vm,$vm_bridge);
print "\tInstall VMs? [y/n]: ";
chomp($install_vm = <STDIN>);
if ($install_vm =~ /y/i){
  #Find out hypervisor
    my $kvm_check = `rpm -qa | grep kvm`;
    my $xen_check = `uname -a | grep xen`;
    
    if ($xen_check ne ""){
        $hyper = "xen";
        print "$hyper detected";

    }elsif ($kvm_check ne ""){
        $hyper = "kvm";
        print "$hyper detected";
    }else{
     print "No kvm/xen hypervisor found\n";
    }
    print "\tTC IP: ";
	chomp($tc_ip = <STDIN>);
}#if
while ( $install_vm =~ /y/i){
  
    my ($inst_path, $vm_autoyast, $virt_type) = (undef);
    print "\tVM Name: ";
	chomp(my $vm_name = <STDIN>);
    if ( $hyper eq "xen"){
        print "\tFull or Para Virt (hvm/paravirt): ";
    	chomp($virt_type = <STDIN>);
    }
    if ( $hyper eq "kvm"){
        $virt_type = "hvm";    
    }
    print "\tVM Mem(MB): ";
	chomp(my $vm_mem = <STDIN>);
    print "\tVM vcpus: ";
	chomp(my $vm_cpus = <STDIN>);
    print "\tVM Disk(/dev/lsys/lv1)): ";
	chomp(my $vm_disk = <STDIN>);
    print "\tVM OS Variant(sles11/sles12/win2k12): ";
	chomp(my $vm_variant = <STDIN>);
        if ($vm_variant =~ /sles11/i){
            print "\t64 or 32 bit?: ";
            chomp(my $vm_arch = <STDIN>);
            if ($vm_arch =~ /64/i){
                $inst_path = "SLES-11-SP3-DVD-x86_64-GM-DVD1";
                $vm_autoyast = "SLES11_SP3-x86_64-single_disk-GRUB.xml";
                $vm_bridge = "br0";
            }elsif( $vm_arch =~ /32/i){
                $inst_path = "SLES-11-SP3-DVD-i586-GM-DVD1";
                $vm_autoyast = "SLES11_SP3-i586-single_disk-GRUB.xml";
                $vm_bridge = "br0";
            }
        }
        elsif( $vm_variant =~ /sles12/i){
            $inst_path = "SLE-12-Server-DVD-x86_64-GM-DVD1";
            $vm_autoyast = "SLE_12-Server-x86_64-single_disk-GRUB.xml";
            $vm_bridge = "br0";
            }
        elsif( $vm_variant =~ /win2k12/i){
            $vm_bridge = "br1";
            if ($hyper =~ /kvm/i){
            system "virt-install --virt-type $hyper --name $vm_name --memory $vm_mem --vcpus=$vm_cpus --disk $vm_disk --os-variant $vm_variant --network=bridge=$vm_bridge --cdrom=/home/win2012_x64.iso --graphics vnc &" ; 
            }elsif($hyper =~ /xen/i){
            system "virt-install --virt-type $hyper --$virt_type --name $vm_name --memory $vm_mem --vcpus=$vm_cpus --disk $vm_disk --os-variant $vm_variant --network=bridge=$vm_bridge --cdrom=/home/win2012_x64.iso --graphics vnc &" ; 

            }
        }
    
        if ( defined($vm_autoyast ) ){
        system "virt-install --virt-type $hyper --$virt_type --name $vm_name --memory $vm_mem --vcpus=$vm_cpus --disk $vm_disk --os-variant $vm_variant --network=bridge=$vm_bridge --location=nfs://$tc_ip/home/InstSource/$inst_path/ --extra-args=autoyast=nfs://$tc_ip/opt/suse/testKits/system/autoyast/$vm_autoyast --graphics vnc &" ; 
        }

sleep(15);  


print "\tInstall another VM? [y/n]";
chomp($install_vm = <STDIN>);
}#while loop
print "Good Bye\n";


