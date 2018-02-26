# Returning a dictioinary
def build_person(first_name, last_name, age=''):
    """Return a dictionary of information about a person"""
    person = {'first':first_name, 'last': last_name}
    if age:
        person['age'] = age
    return person
    
musician = build_person('jimi', 'hendrix', age=41)
print(musician)    

# Using a function with a while loop
def get_formatted_name(first_name, last_name, middle_name=''):
    """Return a full name, neatly formatted."""
    if middle_name:
        full_name = first_name + ' ' + middle_name + ' ' + last_name
    else:
        full_name = first_name + ' ' + last_name
    return full_name.title()
    
while True:
    print("\nPlease tell me your name:")
    print("(enter 'q' at any time to quit)")
    
    f_name = input("First Name: ")
    if f_name == 'q':
        break
            
    l_name = input("Last Name: ")
    if l_name == 'q':
        break
        
    formatted_name = get_formatted_name(f_name,l_name)
    print("\nHello, " + formatted_name + "!")
        
# Passing a list

# Making a copy of a list and passing that instead so original is
# preserved.  Only do this if really necessary.
# function_name(list_name[:])    

# Passing an Arbitrary Number of Arguments using *toppings
# * create a tuple with any num or args from 1 to many
def make_pizza(*toppings):
    """Print the list of toppings that've been requested"""
    print(toppings)
    
make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra_cheese')

# Mixing positional and arbitrary arguments.  Arbitrary must be last
def make_pizza(size, *toppings):
    print("\nMaking a " + str(size) + "-inch pizza with the following" +
            " toppings: ")
    for top in toppings:
        print("- " + top)
        
make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'pineapple', 'meat')        
