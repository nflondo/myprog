# 8-12, 8-13, 

def sandwich_content(*content):
    print("\nItems on the sandwich: ")
    for item in content:
        print("- " + item)
        
sandwich_content('tomatoe')
sandwich_content('tomatoe','onions', 'pickles') 

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
    
user_profile = build_profile('nefi', 'munoz',
                            location = 'payson',
                            field = 'computer science',
                            children = 4)
                            
print (user_profile)           

def make_car(manufacturer, model, **details):
    car_details = {}
    car_details['manufacturer'] = manufacturer
    car_details['model'] = model
    for key,value in details.items():
        car_details[key] = value
        
    return car_details
    
car = make_car('subaru', 'outback', color='blue', tow_package=True)
print(car)
