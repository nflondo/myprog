#!/usr/bin/env python3
import sys,os,subprocess
import cmd_library

#project_data = 'project_data.json'

def execute_cmd(cmd_string):
    #subprocess.call('clear')
    ret = subprocess.call(cmd_string)
    print ("")
    if ret == 0:
        print ("Command executed successfully! :-)")
    else:
        print ("Command terminated with status other than zero :-(")
        input("Press enter")
    print ("")

sutIpAddress = cmd_library.get_tsf_data() 
if not sutIpAddress: # no tsf file found
    sutIpAddress = cmd_library.get_sut_ip_address() # get info without tsf

subprocess.call('clear')
execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', sutIpAddress, '-d','/tmp/', '-p', 'cpu_Hot_Plug-'])
execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', sutIpAddress, '-d','/tmp/', '-p', 'mem_Hot_Plug-'])
execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq-'])
#execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', get_sut_ip_address(), '-d','/tmp/', '-p', 'cpu_Hot_Plug-'])
#execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', sut_ip_address, '-d','/tmp/', '-p', 'mem_Hot_Plug-'])
#execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq-'])
