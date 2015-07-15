#!/usr/bin/perl
# Gathers IBM info from supportconfig files given as arguments
# e.g #./ibm_summary.pl sysfs.txt hardware.txt basic-health-check.txt

#die "Usage:./ibm_summary <filename> [<filename>]" unless @ARGV;

@ARGV = qw( sysfs.txt hardware.txt basic-health-check.txt );

my $bios_version = '';
my $cpu_model = '';
my $cpu_socket = '';
my $tot_mem = 0;
my @dvdinfo, @raidinfo, @pciinfo, @netinfo;


while(<>){
 #chomp;

 if (/bios_version.*=/ & !$bios_version){
  #my $bios = $_ ;
  $bios_version = $_;  
 }

 if (/\Amodel name/ & !$cpu_model){
  #print "$_\n";  
  $cpu_model = $_;
 }

 if (/[S|s]ocket\(s\)/ & !$cpu_socket){
  $cpu_socket = $_;
 }

 if (/\AMem: *(?<tot_mem>[0-9]+) / & !$tot_mem){
  my $mem_kb = $+{tot_mem};  
  my $mem_gig = $mem_kb/(1024 * 1024);
  $tot_mem = $mem_gig ;
 }

 if (/Model:.*DVD/){
  push @dvdinfo,$_ ;
 }
  
if(/Features:.*DVD/){
   push @dvdinfo,$_ ;
} 


 if (/<[0-9]>.*raid/i){
  push @raidinfo,$_ ;
 }

if (/PCI bridge:.*[I\/O|IIO].*Root/){
 push @pciinfo,$_;
 }
if (/Slot ID/i){
 push @pciinfo,$_;
 }

if (/Ethernet controller: .*/){
 push @netinfo,$_;
 }

}
 
print "BIOS: $bios_version";
print "CPU: $cpu_model";
print $cpu_socket;
printf "Total Mem: %.1f GB\n", $tot_mem;
print "---------------------------------------------------\n";
foreach $element (@dvdinfo){
 print "$element\n";
}
print "---------------------------------------------------\n";
foreach $element (@raidinfo){
 print "$element\n";

}
print "---------------------------------------------------\n";
foreach $element (@pciinfo){
 print "$element\n";

}
print "---------------------------------------------------\n";
foreach $element (@netinfo){
 print "$element\n";

}


