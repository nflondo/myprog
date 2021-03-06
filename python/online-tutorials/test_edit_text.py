#!/usr/bin/env python3
find_me = 'DISABLE_POPUPS'
sck_config = '/opt/suse/testKits/system/configs/'
sck_conf_file = 'sck.conf'
# get file content
def disable_pop():
    try:
        with open(sck_config + sck_conf_file, 'r') as f:
            data = f.readlines()
    except FileNotFoundError:
        return None
    print('Initial list: ')
    print(data)
    # change setting
    for index, value in enumerate(data):
        if value.find(find_me) != -1:
            data[index] = 'DISABLE_POPUPS=1\n'
    # write settings
    print('New list: ')
    print(data)
    try:
        with open(sck_config + sck_conf_file, 'w') as f_obj:
            f_obj.writelines(data)            
    except FileNotFoundError:
        return None
    except IndexError: # tsf_file was not found, so list is empty.
        return None    
disable_pop()