import json

# Get stored data if exists
project_data = 'project_data.json'

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