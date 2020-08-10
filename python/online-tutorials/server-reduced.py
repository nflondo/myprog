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

""" # Get stored data if exists
def get_stored_data():
    #Get stored IP address, project name, etc. if available
    try:
        with open(project_data) as f_obj:
            sut_ip_address = json.load(f_obj)
    except FileNotFoundError:
        return None
    else:
        return sut_ip_address

# Get user information (Server IP, log directory name/project name?)
def get_sut_ip_address():
    #Get IP address, project name, etc. if first time running test
    stored_data = get_stored_data()
    if (stored_data):
        return stored_data
    else:    
        sut_ip_address = input("SUT IP Address: ")
        with open(project_data, 'w') as f_obj:
            json.dump(sut_ip_address, f_obj)
        return sut_ip_address """

#get_sut_ip_address()
#execute_cmd_arguments = [get_sut_ip_address()]
#print(execute_cmd_arguments)

subprocess.call('clear')
execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', cmd_library.get_sut_ip_address(), '-d','/tmp/', '-p', 'cpu_Hot_Plug-'])
execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', cmd_library.get_sut_ip_address(), '-d','/tmp/', '-p', 'mem_Hot_Plug-'])
execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq-'])
#execute_cmd(['sh','./cpuHotPlugTest.sh', '-i', get_sut_ip_address(), '-d','/tmp/', '-p', 'cpu_Hot_Plug-'])
#execute_cmd(['sh','./memoryHotPlugTest.sh', '-i', sut_ip_address, '-d','/tmp/', '-p', 'mem_Hot_Plug-'])
#execute_cmd(['sh','./CPU_Frequency_Test', '-d', '/tmp/', '-p', 'CPU_Freq-'])
