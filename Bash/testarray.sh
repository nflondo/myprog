#!/bin/bash

atest[0]='one'
atest[1]='one'

echo "print array: "
echo ${atest[@]}

echo "array size: "
echo ${#atest[*]}

/home/myprog/Bash/kdump-mem
rc=$?

if [ $rc -eq 0 ]; then
	echo "testing passed"
	exit 0
else
	echo "testing failed"
	exit 1
fi
