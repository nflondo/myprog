# dictionaries of pets
minina = {
    'owner': 'Raul',
    'type': 'feline',
    }
    
moo = {
    'owner': 'Larry',
    'type': 'mammal',
    }
    
apex = {
    'owner': 'Liana',
    'type': 'aquatic',
    }
   
pets = [minina, moo, apex]

for animal in pets:
    print("\nOwner: " + animal['owner'].title())    
    print("Type of pet: " + animal['type'].title())    

favorite_places = {
            'anna': ['sandy', 'moab', 'springville'],
            'nefi': ['cancun', 'puerto', 'mazatlan'],
            'liana': ['payson', 'san diego', 'vernal'],
            }
            
for name, places in favorite_places.items():
    print("\nName: " +name)
    for pl in places:
        print("Favorite Places: " + pl.title())
        
# Fav numbers
fav_numbers = {
    'lili': [5, 10], 
    'ben' : [7, 14, 24],
    'anna' : [25, 50, 100],
    'sam' : [3, 5, 7],
    }        

for name, numbers in fav_numbers.items():
    print("\nName: " + name)
    print("Fave numbers: ")
    for num in numbers:
        print(num)
                
