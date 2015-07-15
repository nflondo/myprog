#!/bin/bash


#show amount of mem and number of vcpus available, then ask to decide
TVCPU=`lscpu | grep -e "^CPU(s)" | awk '{print $2}'`
echo -e "Total VCPUs available: $TVCPU"

TMEM="$(cat /proc/meminfo | grep MemTotal:)"
TMEMGB=`$TMEM/1,048,576`
echo -e "Total Mem: $TMEMGB GB "

echo "\tTotal Number of SLES VMS?\c"
read TVMS

for((i=1; i<=$TVMS; i++))
do
echo "\tVM Arch x86_64(x) i586(i):\c"
read VMARCH
if [ $VMARCH = "x" ]; then $VMARCH="x86_64"; elif [ $VMARCH = "i" ]; then $VMARCH="i586" ; fi

echo "\tVM Name:\c"
read VMNAME
echo "\tVM vcpus:\c"
read VMCPU
echo "\tVM Mem (MB)?:\c"
read VMMEM
echo "\tfull(f) or para-virtual(p)?:\c"
read VMMODE
if [ $VMMODE = "f" ]; then $VMMODE="full"; elif [ $VMARCH = "i" ]; then $VMARCH="i586" ; fi
echo "TC IP address:\c"
read TCIP

mount -t nfs "$TCIP":/opt/suse/testKits/system/autoyast/ /mnt

vm-install --background --os-type sles11 -c "$VMCPU" -d /dev/lsys/lv"$i" -m "$VMMEM" --os-settings /mnt/SLES11_SP3-"$VMARCH"-vm.xml --"$VMMODE"-virt --name "$VMNAME" --source nfs://"$TCIP"/home/InstSource/SLES-11-SP3-DVD-"$VMARCH"-GM-DVD1

done

