# ex 6-7 people

fernando = {
    'name':'Fernando', 
    'age':'75', 
    'last_name':'Munoz',
    'city':'West Jordan',
    }

cesar = {
    'name':'cesar', 
    'age':'49', 
    'last_name':'Munoz',
    'city':'jiutepec',
    }
    
alfonso = {
    'name':'alfonso', 
    'age':'51', 
    'last_name':'Munoz',
    'city':'Mexicali',
    }   
    
people = [fernando, cesar, alfonso]

for person in people:
    print("\nName: "+ person['name'].title())
    print("Age: " + person['age'])
    print("Last Name: " + person['last_name'].title())
    print("City: " + person['city'].title())
