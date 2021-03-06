# Passing a parm to a function
# Note docstrings in triple quotes
# username is the parameter and 'jesse' is the argument.  Argument is 
# the value of a parm passed to a function call
def greet_user(username):
    """Display a simple greeting."""
    print("Hello, " + username.title() + "!")
    
greet_user('jesse')    

def display_message():
    '''Display what I'm learning'''
    print("I'm learning about functions, parameters, and arguments")

def fav_book(book_title):
    print("One of my fave books is " + book_title.title())
    
display_message()    
fav_book('Entreleadership')

# Positional Arguments.  Python matches each arg in function call with 
# param in func definition.
def describe_pet(animal_type, pet_name):
    '''Display info about a pet.'''
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
    
describe_pet('hamster', 'Harry')

# Keyword arguments.  Order of arguments doesn't matter here.
describe_pet(animal_type='dog', pet_name='bobby')

# Default Values
def describe_pet2(pet_name, animal_type='dog'):
    '''Display info about a pet.'''
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
    
# param without default value has to be called first, so python can process
# positional arguments correctly
describe_pet2(pet_name='willie')
#or
describe_pet2('charlie')


# Return Values.  Note empty string is FALSE, non-empty is TRUE
# Optional argument has empty string and is last
def get_formatted_name(first_name, last_name, middle_name=''):
    """Return a full name, neatly formatted."""
    if middle_name:
        full_name = first_name + ' ' + middle_name + ' ' + last_name
    else:
        full_name = first_name + ' ' + last_name
    return full_name.title()
    
musician = get_formatted_name('jimi', 'hendrix')
print(musician)

musician = get_formatted_name('john', 'hooker', 'lee')    
print(musician)
