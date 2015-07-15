#!/bin/bash
# Remove and re-create LVM LVs and install VMs on KVM/XEN via cmd line

#=========================================================#
# Used library
#
lib_found=""
libdirs="/opt/suse/testKits/system/lib /usr/lib"

for dir in ${libdirs} ; do
	if [ -x ${dir}/cert_tests.lib ] ; then
		  . ${dir}/cert_tests.lib
		  lib_found="yes"
		  break  # found ; one time is enough
	fi
done
if [ -z "${lib_found}" ] ; then
	>&2 echo -e "\a$0: Needed cert_tests.lib not found in: ${libdirs} . Aborting..."
	exit 1 
fi
unset lib_found libdirs



#=========================================================#
#Set up env and install SLES VMs via cmd line (TODO: Deduce TC IP addr, ask to choose from location or pxe.  If location, then figure out paths)
#
function 12VmInstall(){
echo -e "\t Install VMs?(y/n):\c"
read INSTVMS
if [ "$INSTVMS" == "y" -o "$INSTVMS" == "Y" ]
	then
	echo -e "\tTC IP:\c"
	read TCIP
fi
while [ "$INSTVMS" == "y" -o "$INSTVMS" == "Y" ]
do

	echo -e "\tVirt Type(kvm/xen):\c"
	read VMHYPER
	if [ "$VMHYPER" == "kvm" ]
		then
		:
		else
			echo -e "\tFull or Para Virt (hvm/paravirt):\c"
			read VMTYPE
	fi
	echo -e "\tVM Name:\c"
	read VMNAME
	echo -e "\tVM Mem(MB):\c"
	read VMMEM
	echo -e "\tVM vcpus:\c"
	read VMCPU
	echo -e "\tVM Disk(/dev/lsys/lv1)):\c"
	read VMDISK
	echo -e "\tVM OS Variant(sles11/sles12/win2k12):\c"
	read VMVARIANT
	
	
	case "$VMVARIANT" in
	 sles11)
		echo -e "\t64 or 32 bit?(64/32):\c"
		read ARCH
		if [ "$VMHYPER" == "kvm" ] && [ "$ARCH" == "64" ]
		 then
			virt-install --virt-type $VMHYPER --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/testKits/system/autoyast/SLES11_SP3-x86_64-single_disk-GRUB.xml --graphics vnc --video=qxl &
	    elif [ "$VMHYPER" == "kvm" ] && [ "$ARCH" == "32" ]
			then
			virt-install --virt-type $VMHYPER --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-i586-GM-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/testKits/system/autoyast/SLES11_SP3-i586-single_disk-GRUB.xml --graphics vnc --video=qxl &
		fi
		
		if [ "$VMHYPER" == "xen" ] && [ "$ARCH" == "64" ]
		then
			virt-install --virt-type $VMHYPER --$VMTYPE --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/testKits/system/autoyast/SLES11_SP3-x86_64-single_disk-GRUB.xml --graphics vnc &		
		elif [ "$VMHYPER" == "xen" ] && [ "$ARCH" == "32" ]
			then
			virt-install --virt-type $VMHYPER --$VMTYPE --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-i586-GM-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/testKits/system/autoyast/SLES11_SP3-i586-single_disk-GRUB.xml --graphics vnc &		
		fi
		;;
	 sles12)
		if [ "$VMHYPER" == "kvm" ]
		then
			virt-install --virt-type $VMHYPER --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLE-12-Server-DVD-x86_64-GMC-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/sles12-vm-autoinst.xml --graphics vnc &
	    else
			virt-install --virt-type $VMHYPER --$VMTYPE --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br0 --location=nfs://"$TCIP"/home/InstSource/SLE-12-Server-DVD-x86_64-GMC-DVD1/ --extra-args=autoyast=nfs://"$TCIP"/opt/suse/sles12-vm-autoinst.xml --graphics vnc &
		fi
		;;
	win2k12)
		if [ "$VMHYPER" == "kvm" ]
		then
		virt-install --virt-type $VMHYPER --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br1 --cdrom=/home/win2012_x64.iso --graphics vnc &
		else
		virt-install --virt-type $VMHYPER --$VMTYPE --name $VMNAME --memory $VMMEM --vcpus=$VMCPU --disk $VMDISK --os-variant $VMVARIANT --network=bridge=br1 --cdrom=/home/win2012_x64.iso --graphics vnc &
		fi
		;;
	 *) echo "invalid OS Variant" 
		;;
	esac
	
	sleep 15
	
	echo -e "\t Install another VMs?(y/n):\c"
	read INSTVMS
done

} #function 12VmInstall


echo -e "----------------------------------"
#show amount of mem and number of vcpus available, then ask to decide
TVCPU=`lscpu | grep -e "^CPU(s)" | awk '{print $2}'`
echo -e "Total VCPUs available: $TVCPU"

TMEM="$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')"
TMEMGB=$(($TMEM/1024/1024))
echo -e "Memory $TMEM MB"
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



lvs
printf "\n"
NLV="$(lvs | wc -l)"
if [ $NLV -ge 2 ]
	then
	echo -e "Delete any LVs?(y/n): \c"
	read QDELLV
	
		while [ "$QDELLV" == "y" -o "$QDELLV" == "Y" ]
		do

			echo -e "Name of LV to delete: \c"
			read DELLV
			MPOINT="$(mount | grep $DELLV | awk '{print $3}')"
			#echo "DEBUG:$MPOINT";
			if [ "$MPOINT" != "" ]
			then
				VOLNAME=$(basename $MPOINT)
				umount $MPOINT
			fi
			#Delete from /etc/fstab
			INFSTAB="$(cat /etc/fstab | grep -e "$DELLV")"
			#echo "DEBUG-INFSTAB:$INFSTAB";
			if [ "$INFSTAB" != "" ]
			then
				sed -i '/'$VOLNAME'/d' /etc/fstab
			fi
						
			lvremove -f /dev/lsys/"$DELLV"
			SUCESS=$?
			if [ $SUCESS -eq 0 ]; then
				echo "SUCESS - Removing LV"
			fi
         NLV="$(lvs | wc -l)"
         if [ $NLV -ge 2 ]
         then
			   echo -e "Delete another LV?(y/n): \c"
			   read QDELLV
         else
            break
         fi
		done
	
fi


#create LVs
echo -e "Create any LVs?(y/n): \c"
read QADDLV

if [ "$QADDLV" = "y"  ]
	then
	echo -e "LV Size?(GB): \c"
	read LVSIZE
	echo -e "Number of "$LVSIZE" GB LVs to create: \c"
	read NLV

	for((i=1;i<=$NLV;i++))
	do
	lvcreate -L "$LVSIZE"G -n lv"$i" lsys
	SUCESS=$?
			if [ $SUCESS -eq 0 ]; then
				echo "SUCESS - Creating LV"
			fi
	done
	
fi

if [ "${osVer}" = "12" ] 
then
   12VmInstall
 elif [ "${osVer}" = "11" ] 
 then
   echo "add code for 11"
 else
   echo "OS version not supported"
fi

echo "Good Bye"
exit 0




