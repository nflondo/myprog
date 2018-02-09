# Nesting.  All dictionaries should have identical structure, so you can
# loop and work with them.
# List of dictionaries
aliens = []

# Make 30 green aliens
for alien_number in range(30):
    new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'}
    aliens.append(new_alien)
    
# Modify first 3 aliens
for alien in aliens[0:3]:
    if alien['color'] == 'green':
        alien['color'] = 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10

# Show first 5 aliens
for alien in aliens[:5]:
    print(alien)
print("...")

# show how many aliens have been created
print("Total number of aliens: " + str(len(aliens)))        

# A list in a dictionary
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese'],
    }
    
# Summarize the order
print("You ordered a " + pizza['crust'] + "-crust pizza " +
    "with the following toppings:")
    
for topping in pizza['toppings']:
    print("\t" + topping)
    
# Another list inside a dict    
favorite_languages = {
        'jen': ['python', 'ruby'],
        'sarah': ['c'],
        'edward': ['ruby', 'go'],
        'phil': ['python', 'hasskell'],
        }
        
for name, languages in favorite_languages.items():
    if len(languages) > 1:
        print("\t" + name.title() + "'s favorite languages are:")      
    else:
        print("\t" + name.title() + "'s favorite language is:")
    for lang in languages:
        print("\t" + lang.title()) 
        
# A dictionary in a dictionary
users = {
    'aeinstein': {
        'first': 'albert',
        'last': 'einstein',
        'location': 'princeton',
        },
    'mcurie': {
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
        },
    }
    
for username, user_info in users.items():
    print("\nUsername: " + username)
    full_name = user_info['first'] + " " + user_info['last']
    location = user_info['location']
    
    print("\tFull name: " + full_name.title())
    print("\tLocation: " + location.title())    
        
