#!/bin/bash
# This scripts automates the installation and setup of KVM and XEN software, set up bridge, default bootloader, reboot.

#Remove lvall vol from LVM and fstab
	mount | grep lvall >> /dev/null 2>&1
	if [ $? -eq 0 ]
	then
	echo "umounting /media/lvall and removing the LV" 	
	umount /media/lvall >> /dev/null 2>&1  
	cp /etc/fstab /etc/bak-fstab
	sed -i '/lvall/d' /etc/fstab
	lvremove -f /dev/lsys/lvall
	else
	echo "FYI /media/lvall not mounted"
	fi
HYPERTYPE=""
echo -e "\t Choose KVM(k) or XEN(x): \c"
read HYPERTYPE

case $HYPERTYPE in
	"k" | "K") #KVM software env set up
	
	
	#Install KVM software via Yast so it will prompt for bridge config at the end.
	yast2 -i libvirt libvirt-python vm-install kvm xen-libs virt-manager virt-viewer
	#TODO: Add bridge configuration.  Yast does not prompt me to add bridge at the end.
	
	#For KVM testing,add intel_iommu=on to boot loader via yast or config file (both /etc/elilo.conf and /boot/efi/efi/SuSE/elilo.conf
#new config files: /etc/default/grub, /etc/sysconfig/bootloader, /boot/grub2/grub.cfg 
	grep intel_iommu /boot/efi/efi/SuSE/elilo.conf
	if [ $? -ne 0 ]
	then
	echo "Adding intel_iommu=on"
	cp /etc/elilo.conf /etc/bak.elilo.conf
	cp /boot/efi/efi/SuSE/elilo.conf /boot/efi/efi/SuSE/bak-elilo.conf
	sed -i '/crashkernel/ s| "$| intel_iommu=on "|' /boot/efi/efi/SuSE/elilo.conf
	sed -i '/crashkernel/ s| "$| intel_iommu=on "|' /etc/elilo.conf
	fi
	echo "Please configure Bridge manually"	
	sleep 3
	yast2 lan
	#Reboot
	echo -e "Ready to reboot? (y/n)\c"
	read ANS
	if [ $ANS == "y" ]
	then
	reboot
	fi
	;;
	
	#XEN software and env. set up
	"x" | "X")
	#Detect any running VMs and virsh destroy <vm name>
	#remove intel_iommu=on option from bootloader
	grep intel_iommu /boot/efi/efi/SuSE/elilo.conf
	if [ $? -eq 0 ]
	then
	echo "Removing intel_iommu=on"
	cp /etc/elilo.conf /etc/bak-remove-intel_iommu.elilo.conf
	cp /boot/efi/efi/SuSE/elilo.conf /boot/efi/efi/SuSE/bak-remove-intel_iommu.elilo.conf
	sed -i 's|intel_iommu=on ||g' /boot/efi/efi/SuSE/elilo.conf
	sed -i 's|intel_iommu=on ||g' /etc/elilo.conf
	fi
	#Install xen software via Yast in case bridge need to be set up
	yast2 -i libvirt libvirt-python vm-install xen xen-tools kernel-xen xen-libs virt-manager virt-viewer
	#set xen as default kernel in bootloader
	
	cp /etc/elilo.conf /etc/bak-default.elilo.conf
	cp /boot/efi/efi/SuSE/elilo.conf /boot/efi/efi/SuSE/bak-default-elilo.conf
	sed -i 's/default = .*/default = Xen/' /etc/elilo.conf
	if [ $? -eq 0 ]
	then
		echo "SUCCESS - XEN to default in /etc/elilo.conf"
		sleep 3
	else
		echo "FAILED - XEN to default in /etc/elilo.conf"
		sleep 3
	fi
	sed -i 's/default = .*/#default = Xen/' /boot/efi/efi/SuSE/elilo.conf
	if [ $? -eq 0 ]
	then
		echo "SUCCESS - XEN to default in /boot/efi/efi/SuSE/elilo.conf"
		sleep 3
	else
		echo "FAILED - XEN to default in /boot/efi/efi/SuSE/elilo.conf"
		sleep 3
	fi
	
	echo "Please configure Bridge manually"
		sleep 3
	yast2 lan
	#Reboot
	echo -e "Ready to reboot? (y/n)\c"
	read ANS
	if [ $ANS == "y" ]
	then
	reboot
	fi
	;;
esac

exit 0;
