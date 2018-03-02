def sandwich_content(*content):
    print("\nItems on the sandwich: ")
    for item in content:
        print("- " + item)
        

# Using arbitrary keyword args.  Accept as many key-value pairs as 
# provided

def build_profile(first, last, **user_info):
    """Build a dict containing everything we know about a user."""
    profile = {}
    profile['first_name'] = first
    profile['last_name'] = last
    for key, value in user_info.items():
        profile[key] = value
        
    return profile
    

def make_car(manufacturer, model, **details):
    car_details = {}
    car_details['manufacturer'] = manufacturer
    car_details['model'] = model
    for key,value in details.items():
        car_details[key] = value
        
    return car_details
