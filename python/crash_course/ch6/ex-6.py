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
    'tuple': 'An immutable list',
    'key': 'Index in a dictionary',
    'value': 'The value of the key',
    }
    
for key, value in glossary.items():
    print("\n" + key.title() + ": " + value)
    
rivers = {
    'nile': 'Egipt',
    'amazon': 'Brazil',
    'jordan': 'Israel',
    }
for key in rivers.keys():
    print("The " + key + " runs through " + rivers[key].title())
    
for river in rivers.keys():
    print(river)    
        
for country in rivers.values():
    print(country) 
    
favorite_languages = {
        'jen': 'python',
        'sarah': 'c',
        'edward': 'ruby',
        'phil': 'python',
        }

candidates = ['jim', 'bruce', 'jen','phil', 'ann']

for candidate in candidates:
    if candidate in favorite_languages.keys():
        print("Thank you for taking the poll, " + candidate.title())
    else:
        print(candidate.title() + ", please take the poll.  Thanks !")
