# Dic for person
person = {
    'name':'Fernando', 
    'age':'75', 
    'last_name':'Munoz',
    'city':'West Jordan',
    }
    
# the items() method is part of a dict    
for key, value in person.items():
    print("\nKey: " + key)
    print("Value: " + value)

# Fav numbers
fav_numbers = {
    'lili': 5,
    'ben' : 7,
    'anna' : 25,
    'sam' : 3,
    }
    
for key, value in fav_numbers.items():
    print("\nKey: " + key)
    print("Value: " + str(value))
    
glossary = {
    'dictionary': 'A collection of key-value pairs',
    'list': 'A collection of items in a particular order',
    'tuple': 'An immutable list'
    }
    
for key, value in glossary.items():
    print("\n" + key.title() + ": " + value)
    
