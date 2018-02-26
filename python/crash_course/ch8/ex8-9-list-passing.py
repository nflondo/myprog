# ex 8-9, 8-10, 8-11

def make_great(magicians_list):
    great_list = []
    while magicians_list:
        current_magician = magicians_list.pop()
        current_magician += ' the Great'
        great_list.append(current_magician)
        
    while great_list:
        current_magician = great_list.pop()
        magicians_list.append(current_magician)
        
def show_magicians(names_list):
    for name in names_list:
        print(name)   
    
# Initial list
magicians = ['david copperfield', 'merlin', 'brozo']
show_magicians(magicians)

# Modify the list
make_great(magicians)

# Show the list has been modified
show_magicians(magicians)
