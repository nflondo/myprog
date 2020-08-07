#!/usr/bin/env python3
import sys,os,subprocess

def execute_cmd(cmd_string):
    subprocess.call('clear')
    ret = subprocess.call(cmd_string)
    print ("")
    if ret == 0:
        print ("Command executed successfully! :-)")
    else:
        print ("Command terminated with status other than zero :-(")
        input("Press enter")
    print ("")    

execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq_'])
execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', '10.1.1.3', '-d','/tmp/', '-p', 'Mem_Hot_Plug_'])

