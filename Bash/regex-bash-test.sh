#!/bin/bash

#TestCmdLine="-l -d Bug1196463-test -i 10.1.1.10 -p Get_MVM_Test_Logs -t /opt/suse/testKits/system/bin/gatherlogs -i ~vm-ipaddr~ -f Virtualization_Reduced"
#TestCmdLine="-f Virtualization_Reduced -l -d Bug1196463-test -i 10.1.1.10 -p Get_MVM_Test_Logs -t /opt/suse/testKits/system/bin/gatherlogs -i ~vm-ipaddr~"
TestCmdLine="-l -d Bug1196463-test -f Virtualization_Reduced -i 10.1.1.10 -p Get_MVM_Test_Logs -t /opt/suse/testKits/system/bin/gatherlogs -i ~vm-ipaddr~"
echo "   TestCmdLine=$TestCmdLine"
#TestCmdLine=${TestCmdLine/-f\w+\s/}
TestCmdLine=$(echo $TestCmdLine | sed 's/-f [a-zA-Z_]\+//g')
echo "2- TestCmdLine:$TestCmdLine"
exit 1