# Dictionaries
aliens = {'color':'green', 'points':5}
#print(aliens['color'])
#print(aliens['points'])
print(aliens)

aliens['x'] = 0
aliens['y'] = 25
print(aliens)

aliens['color'] = 'red'
print(aliens)

# Removing key-value pairs with del permanently
del aliens['points']
print(aliens)

# Looping through keys in a dictionary with keys() This is default
# behaviour
fav_numbers = {
    'lili': 5,
    'ben' : 7,
    'anna' : 25,
    'sam' : 3,
    }

friends = ['sam', 'anna']    
for name in fav_numbers.keys():
    print(name.title())  
    if name in friends:
        print(" Hi " + name.title() + "," + 
            "I see your favority number is: " + str(fav_numbers[name]))

# keys() actually returns a list of all the keys
if 'erin' not in fav_numbers.keys():
    print("Erin, please take our poll !!")

# Looping through keys in order with sorted()
for name in sorted(fav_numbers.keys()):
    print(name.title() + ", thank you for taking the poll.")
    
# Looping through all values in a dictionary with values()
print("The following numbers have been mentioned:")
for num in fav_numbers.values():
    print(num)
    
# To avoid repeating values use set()    
print("The following numbers have been mentioned:")
for num in set(fav_numbers.values()):
    print(num)    

# A list of dictionaries
alien0 = {'color': 'green', 'points': 5}
alien1 = {'color': 'yellow', 'points': 10}
alien2 = {'color': 'red', 'points': 15}

aliens = [alien0, alien1, alien2]

for alien in aliens:
    print(alien)
