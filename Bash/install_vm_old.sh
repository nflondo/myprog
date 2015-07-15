#!/bin/bash
# Automate KVM and XEN VM installs via vm-install or virt-install
#
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
function vmInstall12(){
# 1 = KVM   
# 2 = XEN
# 3 = No supported hypervisor
if [ $1 -eq 1 ]
then
 VMHYPER="kvm"
elif [ $1 -eq 2 ]
then 
  VMHYPER="xen"
else
   continue
fi


echo -e "\tInstall VMs?(y/n): \c"
read INSTVMS
if [ "${INSTVMS}" == "y" -o "${INSTVMS}" == "Y" ]
	then
	echo -e "\tTC IP:\c"
	read TCIP
fi
while [ "${INSTVMS}" == "y" -o "${INSTVMS}" == "Y" ]
do

	if [ "${VMHYPER}" == "xen" ]
		then
			echo -e "\tFull or Para Virt (hvm/paravirt): \c"
			read VMTYPE
	fi
	echo -e "\tVM Name:\c"
	read VMNAME
	echo -e "\tVM Mem(MB):\c"
	read VMMEM
	echo -e "\tVM vcpus:\c"
	read VMCPU
	echo -e "\tVM Disk path or size in GB for default image location (e.g \"/dev/sda5\", \"/dev/volGroup/lvmVol\", or \"10\"): \c"
	read VMDISK
   if [[ ${VMDISK} =~ ^[0-9]+$ ]]
   then
      VMDISK_DEF="size=${VMDISK}"
      VMDISK=${VMDISK_DEF}
   fi    
	echo -e "\tVM OS Variant(sles11/sles12/win2k12): \c"
	read VMVARIANT
	
	
	case "${VMVARIANT}" in

	 sles11)
		echo -e "\t64 or 32 bit?(64/32): \c"
		read ARCH
		if [ "${VMHYPER}" == "kvm" ] && [ "${ARCH}" == "64" ]
		 then
			virt-install --virt-type ${VMHYPER} --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-x86_64-single_disk-GRUB.xml --graphics vnc --video=qxl  &
	    elif [ "${VMHYPER}" == "kvm" ] && [ "${ARCH}" == "32" ]
			then
			virt-install --virt-type ${VMHYPER} --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-i586-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-i586-single_disk-GRUB.xml --graphics vnc --video=qxl  &
		fi
		
		if [ "${VMHYPER}" == "xen" ] && [ "${ARCH}" == "64" ]
		then
			virt-install --virt-type ${VMHYPER} --$VMTYPE --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-x86_64-single_disk-GRUB.xml --graphics vnc  &		
		elif [ "${VMHYPER}" == "xen" ] && [ "${ARCH}" == "32" ]
			then
			virt-install --virt-type ${VMHYPER} --$VMTYPE --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-i586-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-i586-single_disk-GRUB.xml --graphics vnc  &		
		fi
		;;

	 sles12)
		if [ "${VMHYPER}" == "kvm" ]
		then
			virt-install --virt-type ${VMHYPER} --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLE-12-Server-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLE_12-Server-x86_64-single_disk-GRUB.xml --graphics vnc  &
	    else
			virt-install --virt-type ${VMHYPER} --$VMTYPE --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br0 --location=nfs://"${TCIP}"/home/InstSource/SLE-12-Server-DVD-x86_64-GM-DVD1/ --extra-args=autoyast=nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLE_12-Server-x86_64-single_disk-GRUB.xml --graphics vnc  &
		fi
		;;

	win2k12)
		if [ "${VMHYPER}" == "kvm" ]
		then
		virt-install --virt-type ${VMHYPER} --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br1 --cdrom=/home/win2012_x64.iso --graphics vnc  &
		else
		virt-install --virt-type ${VMHYPER} --$VMTYPE --name ${VMNAME} --memory ${VMMEM} --vcpus=${VMCPU} --disk ${VMDISK} --os-variant ${VMVARIANT} --network=bridge=br1 --cdrom=/home/win2012_x64.iso --graphics vnc  &
		fi
		;;
	 *) echo "invalid OS Variant" 
		;;
	esac
	
	sleep 15
	
	echo -e "\tInstall another VMs?(y/n): \c"
	read INSTVMS
done

}  #End of function

#==============================================================================
# function vmInstall11
#
function vmInstall11(){
# 1 = KVM   
# 2 = XEN
# 3 = No supported hypervisor
if [ $1 -eq 1 ]
then
 VMHYPER="kvm"
 VMTYPE="V"
elif [ $1 -eq 2 ]
then 
  VMHYPER="xen"
else
   continue
fi


echo -e "\tInstall VMs?(y/n): \c"
read INSTVMS
if [ "${INSTVMS}" == "y" -o "${INSTVMS}" == "Y" ]
	then
	echo -e "\tTC IP:\c"
	read TCIP
fi
while [ "${INSTVMS}" == "y" -o "${INSTVMS}" == "Y" ]
do

	echo -e "\tVM Name:\c"
	read VMNAME
    echo -e "\tVM VM OS 1) sles11-x86_64, 2) sles11-i586, 3)winserver2012x64: \c"
	read VMFLAVOR

	if [ "${VMHYPER}" == "xen" ]
		then
			echo -e "\t1) Full or 2) Para Virt: \c"
			read READVMTYPE
			if [ $READVMTYPE -eq 1 ]
			then
			    VMTYPE="V"
            fi			
            if [ $READVMTYPE -eq 2 ]
			then 
			  VMTYPE="v"
			    
			fi
	fi
	echo -e "\tVM Mem(MB): \c"
	read VMMEM
	echo -e "\tVM vcpus: \c"
	read VMCPU
	echo -e "\tVM Disk path (e.g \"/dev/sda5\", \"/dev/volGroup/lvmVol\"): \c"
	read VMDISK
	
		
	if [ "${VMFLAVOR}" -eq "1" ]
	then
		VMVARIANT="sles11"
		AUTOYAST="nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-x86_64-single_disk-GRUB.xml"
		INSTSOURCE="nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-x86_64-GM-DVD1"

        if [ "${VMHYPER}" == "kvm" -o "${VMTYPE}" == "v" ]		
        then
vm-install --os-type ${VMVARIANT} -c ${VMCPU} -d ${VMDISK} -m ${VMMEM} -${VMTYPE} --name ${VMNAME} --os-settings "${AUTOYAST}" --source "${INSTSOURCE}" &
        fi
        if   [ "${VMHYPER}" == "xen" ] && [ "${VMTYPE}" == "V" ]	
        then					
vm-install --os-type ${VMVARIANT} -c ${VMCPU} -d ${VMDISK} -m ${VMMEM} -${VMTYPE} --name ${VMNAME} -p ${TCIP} &
        fi

        
	fi

	if [ "${VMFLAVOR}" -eq "2" ]
	then
		VMVARIANT="sles11"
		AUTOYAST="nfs://"${TCIP}"/opt/suse/testKits/system/autoyast/SLES11_SP3-i586-single_disk-GRUB.xml"
		INSTSOURCE="nfs://"${TCIP}"/home/InstSource/SLES-11-SP3-DVD-i586-GM-DVD1"
        
        if [ "${VMHYPER}" == "kvm" -o "${VMTYPE}" == "v" ]		
        then
		    vm-install --os-type ${VMVARIANT} -c ${VMCPU} -d ${VMDISK} -m ${VMMEM} -${VMTYPE} --name ${VMNAME} --os-settings "${AUTOYAST}" --source "${INSTSOURCE}" &  
	    fi
        if   [ "${VMHYPER}" == "xen" ] && [ "${VMTYPE}" == "V" ]	
        then	
            vm-install --os-type ${VMVARIANT} -c ${VMCPU} -d ${VMDISK} -m ${VMMEM} -${VMTYPE} --name ${VMNAME} -p ${TCIP} &	
        fi			
	fi		
	if [ "${VMFLAVOR}" -eq "3" ]
	then		
		
		echo -e "\tPath to Windows ISO (e.g. /home/win2012_x64.iso): \c"
		read ISOPATH
		VMVARIANT="winserver2012"
		vm-install --os-type ${VMVARIANT} -c ${VMCPU} -d ${ISOPATH},1,cdrom -d ${VMDISK} -m ${VMMEM} --name ${VMNAME} --source ${ISOPATH} &
	fi

echo -e "\tInstall another VMs?(y/n): \c"
read INSTVMS
done
} #function vmInstall11

function getHypervisor(){
   #Find out hypervisor
   # 1 = KVM   
   # 2 = XEN
   # 3 = No supported hypervisor
    KVMCHECK=`rpm -qa | grep kvm`
    XENCHECK=`uname -a | grep xen`
    
    if [ ! -z "${XENCHECK}" ]
    then
        HYPER=2
        echo "XEN detected"

    elif [ ! -z "${KVMCHECK}" ]
    then
        HYPER=1
        echo "KVM detected"
    else
      #echo "No kvm/xen hypervisor found\n"
      HYPER=3
      echo "No KVM or XEN hypervisor found. Run Yast to install hypervisor now? (y/n)\c"
      read RUNYAST
      if [ ${RUNYAST} == "y" -o ${RUNYAST} == "Y" ] && [ "${osVer}" = "11" ]
      then
         yast2 xen
      elif [ ${RUNYAST} == "y" -o ${RUNYAST} == "Y" ] && [ "${osVer}" = "12" ]
      then
         yast2 virtualization
      else
       continue   
      fi
      
   fi
   return ${HYPER}

}

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

  
getHypervisor

if [ "${osVer}" = "12" ] 
then
   vmInstall12 ${HYPER}
elif [ "${osVer}" = "11" ] 
then
   vmInstall11 ${HYPER}
else
     echo "OS version not supported"
fi

echo "Good Bye"
exit 0
