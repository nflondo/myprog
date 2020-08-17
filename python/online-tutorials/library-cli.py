#!/usr/bin/env python3
import json, glob, subprocess

# Get stored data if exists
project_data = 'project_data.json'
#=============================================================================#
# Get IP address from tsf file.
# 
def get_tsf_data():
    """Get IP address from tsf file"""
    tsfFile = glob.glob("*.tsf") # tsfFile is a list
#Debug    print("tstFile: ", tsfFile)
    listData = []
    lineNum = 0
    substr = "[SUT IP Address]".lower() # substring to search for
    secondSubstr = "Station IP Address".lower() # second search term

    try:
        with open(tsfFile[0], 'rt') as f_obj: # grab first element in list
            for line in f_obj:
                lineNum += 1
                if line.lower().find(substr) != -1: # case-insensitive match
                    if substr != secondSubstr:
                        substr = secondSubstr            
                        listData.append("Line " + str(lineNum) + ": " + line.rstrip('\n'))
                    else:
                        listData.append("Line " + str(lineNum) + ": " + line.rstrip('\n'))
                        break        
    except FileNotFoundError:
        return None
    except IndexError: # tsfFile was not found, so list is empty.
        return None

    equalSignPosition = listData[1].find("=") # find position of equal sign
    sutIpAddr = listData[1][equalSignPosition + 1:] # get second part of the string

    return sutIpAddr
#=============================================================================#
#  Get stored IP address, project name, etc. from user json file if available
#
def get_stored_data():
    """Get stored IP address, project name, etc. from user json file if available"""
    try:
        with open(project_data) as f_obj:
            sut_ip_address = json.load(f_obj)
    except FileNotFoundError:
        return None
    else:
        return sut_ip_address
#=============================================================================#
# Get IP address, from user and into json file if first time running test
#
def get_sut_ip_address():
    """Get IP address, from user and into json file if first time running test"""
    stored_data = get_stored_data()
    if (stored_data):
        return stored_data
    else:    
        sut_ip_address = input("SUT IP Address: ")
        with open(project_data, 'w') as f_obj:
            json.dump(sut_ip_address, f_obj)
        return sut_ip_address
#=============================================================================#
# Function uses a dictionary to simulate a switch statement in python (since
# switch does not exists in python ATM)
#  
def switch_func(return_value):
    switcher = {
        0: "PASS",
        1: "FAIL",
        2: "PASS_W_WARNING",
        3: "NOT_APPLICABLE",
        4: "NOT_SUPPORTED",
        5: "NOT_TESTABLE"
    }
    print (switcher.get(return_value, "Invalid Return Value"))
#=============================================================================#
# Executes commands in linux shell
#
def execute_cmd(cmd_string):
#    subprocess.call('clear')
    return_code = subprocess.call(cmd_string)
    # Translates return code into string
    switch_func(return_code)
