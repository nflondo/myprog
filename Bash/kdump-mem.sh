#!/bin/bash
#This program tells you the amount of memory reserved for kdump

#  This should come back with an address such as "02000000-05ffffff : Crash kernel"  
###F1F2="02000000-05ffffff : Crash kernel"
F1F2=$(fgrep 'Crash kernel' /proc/iomem | cut -d: -f1)

echo "F1F2 = $F1F2"

F1=$(echo $F1F2 | cut -d- -f1)
echo "F1 = $F1"

F2=$(echo $F1F2 | cut -d- -f2)
echo "F2 = $F2"
#KMEM="$(((0x$F2-0x$F1)/1024/1024))"
#For command below, reverse the order of the address.  
echo "$[(0x$F2-0x$F1)/1024/1024] MB of crash kernel"
#echo $KMEM

