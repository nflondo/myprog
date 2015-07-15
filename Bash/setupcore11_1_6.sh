#!/bin/bash
#################################################################### 
# SLES 11 script.  
# This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; version 2 of the License.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  Authors/Contributors:
#     Nefi Munoz(nmunoz@novell.com), Chris Embree (christopher.embree@cardinalhealth.com)
#     
#####################################################################


## Check if coredump already set up

## The following tests all return 0 if things are correctly installed for KDUMP

#grep crashkernel /boot/grub/menu.lst
#GRUB=$?
#rpm -q kdump kexec-tools kernel-kdump
#RPM=$?
#grep DUMPFORMAT\=\"compressed\" /etc/sysconfig/kdump
#COMPRESSED=$?
#grep DUMPLEVEL\=\"15\" /etc/sysconfig/kdump
#DUMPLEVEL=$?

#echo "Grub: $GRUB"
#echo "RPM: $RPM"
#echo "Compressed: $COMPRESSED"
#echo "DumpLevel: $DUMPLEVEL"

## Add up all of our values...
#let INSTALLED=$"$GRUB+$RPM+$COMPRESSED+$DUMPLEVEL"

## If any of the above are > 0, we want to re-install; otherwise we're good and exit Now.
#if [ $INSTALLED -lt 1 ]; then
#        exit 0
#fi

##Check version of SLES and quit if wrong version of script for OS
OSVER="$(cat /etc/SuSE-release | grep 11)"
if [ $? -eq 1 ]
then
echo "Quitting setupcore script because this script was not written for this OS version"
exit
fi

#Check if NFS eit-linux-data is mounted
if [ `mount | grep /mnt/eit-linux-data | wc -l` -ne "1" ]
 then
 echo "Aborting because \"/mnt/eit-linux-data\" does not appear to be mounted"
 exit
fi


#1. Verify the packages kdump, kexec-tools, and makedumpfile are installed, if not install them.

rpm -q kdump kexec-tools makedumpfile || zypper in -y kdump kexec-tools makedumpfile

## Check if software got installed

if [ ! -e /sbin/kdump ]
 then
 echo "Aborting because kdump package is NOT installed. Is the installation source accesible?"
 exit
fi


#2. Edit /etc/sysconfig/sysctl, change the ENABLE_SYSRQ line to ENABLE_SYSRQ="yes".
## Safety first:  We'll make a backup copy of sysctl
cp /etc/sysconfig/sysctl /etc/sysconfig/sysctl-pre-kdump-install

SYSRQTEST="$(grep ENABLE_SYSRQ /etc/sysconfig/sysctl)"

if [ -n "$SYSRQTEST" ]
 then 
  sed -i 's/ENABLE_SYSRQ=.*/ENABLE_SYSRQ="yes"/' /etc/sysconfig/sysctl
 else
  echo "ENABLE_SYSRQ=\"yes\"" >> /etc/sysconfig/sysctl
fi

#3. Edit /boot/grub/menu.lst  and add parameter "crashkernel=xxM" to primary "kernel" based on server memory size per table below.  First figure out amount of memory then set parameter accordingly.

## Safety first:  We'll make a backup copy of menu.lst
cp /boot/grub/menu.lst /boot/grub/menu.lst.pre-kdump-install

## Since some servers have kernel params set without having kdump installed... we'll clear any existing params for kdump.
## first we remove it from the middle.
sed -i 's|crashkernel.* ||g' /boot/grub/menu.lst

## Now removed it from the end
sed -i 's|crashkernel.*$||g' /boot/grub/menu.lst


# This gives me system memory in Kb. 1 Gb = 1048576Kb
RAMKB="$(cat /proc/meminfo | grep MemTotal | awk '{print $2}')"
RAMGB=$(($RAMKB/1048576))
#Test RAMGB=15

#crashkernel=
#0 - 12 GB	256M
#13 - 48 GB	256M
#49 - 128 GB	512M
#129 - 256 GB	512M
#256 - 512 GB  1024M 

if   [ $RAMGB -lt  12 ]                  ; then sed -i '/splash/ s|$| crashkernel=256M|' /boot/grub/menu.lst
elif [ $RAMGB -lt  48 -a $RAMGB -gt  12 ]; then sed -i '/splash/ s|$| crashkernel=256M|' /boot/grub/menu.lst
elif [ $RAMGB -lt 128 -a $RAMGB -gt  49 ]; then sed -i '/splash/ s|$| crashkernel=512M|' /boot/grub/menu.lst
elif [ $RAMGB -lt 256 -a $RAMGB -gt 129 ]; then sed -i '/splash/ s|$| crashkernel=512M|' /boot/grub/menu.lst
elif [ $RAMGB -lt 513 -a $RAMGB -gt 256 ]; then sed -i '/splash/ s|$| crashkernel=1024M|' /boot/grub/menu.lst
else
  echo "out of range"
fi


#4- Edit /etc/sysconfig/kdump and set the following parameters: KDUMP_SAVEDIR="nfs://servername/kdmp"; KDUMP_DUMPLEVEL="15"; KDUMP_DUMPFORMAT="compressed"

#Get NFS server name
NFS_SERV=$(mount | grep eit-linux-data | cut -d: -f1)

#Get path for kdump in NFS server
NFS_PATH=$(mount | grep eit-linux-data | cut -d: -f2 | sed 's/ .*//')

mkdir -p /mnt/eit-linux-data/kdump > /dev/null 2>&1

sed -i "s|KDUMP_SAVEDIR=.*|KDUMP_SAVEDIR=\"nfs://$NFS_SERV$NFS_PATH/kdump\"|" /etc/sysconfig/kdump
sed -i 's/KDUMP_DUMPLEVEL=.*/KDUMP_DUMPLEVEL="15"/' /etc/sysconfig/kdump
sed -i 's/KDUMP_DUMPFORMAT=.*/KDUMP_DUMPFORMAT="compressed"/' /etc/sysconfig/kdump


#5- Activate the kdump system service.  Run "chkconfig kdump on"

chkconfig boot.kdump on

# (not needed since rebooting)Reload kdump to assure any new settings take effect
#rckdump restart

#6- Reboot

#echo "SUCCESS !! Please reboot this server to finalize coredump setup"
