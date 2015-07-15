#!/bin/bash
# Remove and re-create LVM LVs and install VMs on KVM/XEN via cmd line

echo -e "----------------------------------"
#show amount of mem and number of vcpus available, then ask to decide
TVCPU=`lscpu | grep -e "^CPU(s)" | awk '{print $2}'`
echo -e "Total VCPUs available: $TVCPU"

TMEM="$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')"
TMEMGB=$(($TMEM/1048576))
echo -e "Total Memory: $TMEMGB GB"
echo -e "----------------------------------"
echo -e "\n"
#TODO: shutdown any kvm or xen machines running
#LIST_VM=`virsh list | grep running | awk '{print $2}'`
#for i in $LIST_VM
#do
#virsh -c qemu:///system destroy $i >/dev/null
#done
#fi

#xm list
#

#Delete LVs if any
lvscan | grep lv
if [ $? -eq 0 ]
	then
	echo -e "Delete any LVs?(y/n): \c"
	read QDELLV
	if [ "$QDELLV" = y  ]
		then
		echo -e "Number of LVs to delete: \c"
		read DELLV

		for((i=1;i<=$DELLV;i++))
			do
			lvremove -f /dev/lsys/lv"$i"
	
		done
	else
	:
	fi
fi


#create LVs
echo -e "Create any LVs?(y/n): \c"
read QADDLV
if [ "$QADDLV" = y  ]
then
	echo -e "Number of 30 GB LVs to create: \c"
	read NLV

	for((i=1;i<=$NLV;i++))
	do
	lvcreate -L 30G -n lv"$i" lsys
	done
fi

#Set up env and install SLES VMs via cmd line (TODO: Deduce TC IP addr)
echo -e "\tPlease Enter TC IP address:\c"
read TCIP

mount | grep mymnt >> /dev/null 2>&1;
if [ "$?" -ne 0 ]
then
	
	ls /media/mymnt	>> /dev/null 2>&1
	if [ "$?" -ne 0 ]; then mkdir /media/mymnt; fi
	mount -t nfs "$TCIP":/opt/suse/testKits/system/autoyast/ /media/mymnt >> /dev/null 2>&1
fi

#echo -e "\tPlease Enter Total Number of SLES VMS?\c" TODO: Allow to specify total # of VMs and figure out the rest
#read TVMS
#for((i=1; i<=$TVMS; i++))
#How much mem in VMs? (guess this in the future)
#How many vcpus in VMs?(guess this in the future)
#How many full-virt sles?
#How many para-virt sles?
#How many windows VMs?
	#Guess name
	#Guess Mode
	#Guess arch (all 64 bit)
	#Guess diks
lvscan | grep lv >> /dev/null 2>&1;
if [ "$?" -eq 0 ]
then
VMDISK=1;
fi

echo -e "\tVM Mem (MB)?:\c"
read VMMEM
echo -e "\tVM vcpus:\c"
read VMCPU
echo -e "\tNumber of SLES Fully-Virtualized:\c"
read VMFULL
echo -e "\tNumber of SLES Para-Virtualized:\c"
read VMPARA
echo -e "\tNumber of Windows VMs:\c"
read VMWIN
#TODO:CHECK total number of requested vms against available lvx LVs
#TODO: scp win iso from TC to SUT in prep for win installs	
if [ ! -z "$VMFULL" ] && [ "$VMFULL" -gt 0  ]
then
	for((i=1; i<=$VMFULL; i++))
	do
		vm-install --os-type sles11 -c "$VMCPU" -d /dev/lsys/lv"$VMDISK" -m "$VMMEM" --full-virt --name SLES-FV-"$VMDISK" -p "$TCIP" &
		VMDISK=$((VMDISK+1))
	done

fi

if [ ! -z "$VMPARA" ] && [ "$VMPARA" -gt 0  ]
then
	for((i=1; i<=$VMPARA; i++))
	do
		
vm-install --background --os-type sles11 -c "$VMCPU" -d /dev/lsys/lv"$VMDISK" -m "$VMMEM" --os-settings /media/mymnt/SLES11_SP3-x86_64-single_disk.xml --para-virt --name SLES-PV-"$VMDISK" --source nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1 &
#vm-install --os-type sles11 -c "$VMCPU" -d /dev/lsys/lv"$VMDISK" -m "$VMMEM" --para-virt --name SLES-PV-"$VMDISK" -p "$TCIP" &
		VMDISK=$((VMDISK+1))
	done

fi

if [ ! -z "$VMWIN" ] && [ "$VMWIN" -gt 0  ]
then
	for((i=1; i<=$VMWIN; i++))
	do
		 vm-install --os-type winserver2012 -c "$VMCPU" -d /root/win2012_x64.iso,1,cdrom -d /dev/lsys/lv3 -m "$VMMEM" --name Win2012-"$VMDISK" --source /root/win2012_x64.iso &
	done
fi		

exit 0
