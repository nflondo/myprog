#!/usr/bin/env python3
import json, glob

# Get stored data if exists
project_data = 'project_data.json'

def get_tsf_data():
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
    sutIpAddr = listData[1][equalSignPosition + 1:] # get part of the string

    return sutIpAddr

def get_stored_data():
    """Get stored IP address, project name, etc. if available"""
    try:
        with open(project_data) as f_obj:
            sut_ip_address = json.load(f_obj)
    except FileNotFoundError:
        return None
    else:
        return sut_ip_address

# Get user information (Server IP, log directory name/project name?)
def get_sut_ip_address():
    """Get IP address, project name, etc. if first time running test"""
    stored_data = get_stored_data()
    if (stored_data):
        return stored_data
    else:    
        sut_ip_address = input("SUT IP Address: ")
        with open(project_data, 'w') as f_obj:
            json.dump(sut_ip_address, f_obj)
        return sut_ip_address