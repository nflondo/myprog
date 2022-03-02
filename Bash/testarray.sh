#!/bin/bash

# atest[0]='10.1.1.5'
# atest[1]='10.1.1.6'
# atest[2]='10.1.1.7'
atest=$(cat /tmp/ip-vms-10.1.1.10 2> /dev/null | sort | uniq)
count=0
atest_array=""
TestCmdLine="-l -d Bug1196463-test -i 10.1.1.10 -p Get_MVM_Test_Logs -t /opt/suse/testKits/system/bin/gatherlogs -i ~vm-ipaddr~ -f Virtualization_Reduced"
#TestCmdLine="-f Virtualization_Reduced -l -d Bug1196463-test -i 10.1.1.10 -p Get_MVM_Test_Logs -t /opt/suse/testKits/system/bin/gatherlogs -i ~vm-ipaddr~"
echo "   TestCmdLine=$TestCmdLine"
#TestCmdLine=${TestCmdLine/-f\w+\s/}
TestCmdLine=$(echo $TestCmdLine | sed 's/-f(.*)(.*)//g')
echo "2- TestCmdLine:$TestCmdLine"
exit 1
for element in ${atest};do
	atest_array[count]=$element
	count=$(( ++count ))
done
echo "print array: "
echo ${atest_array[@]}

echo "array size: "
echo ${#atest_array[@]}

echo "array keys: "
echo ${!atest_array[@]}

array_size=${#atest_array[@]}
last_element=${atest_array[-1]}
for ipAddr in "${atest_array[@]}";do
	
	echo -e "Array element: $ipAddr"
	if [ $ipAddr == $last_element ];then
		echo "Last element: $ipAddr"
		TestCmdLine=sed /-f //$TestCmdLine
	fi
	
done

# /home/myprog/Bash/kdump-mem
# rc=$?

# if [ $rc -eq 0 ]; then
# 	echo "testing passed"
# 	exit 0
# else
# 	echo "testing failed"
# 	exit 1
# fi
