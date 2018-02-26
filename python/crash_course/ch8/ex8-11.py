# 8-11

def make_great(magicians_list):
    great_list = []
    while magicians_list:
        current_magician = magicians_list.pop()
        current_magician += ' the Great'
        great_list.append(current_magician)
        
    while great_list:
        current_magician = great_list.pop()
        magicians_list.append(current_magician)
        
    return magicians_list
        
def show_magicians(names_list):
    for name in names_list:
        print(name)   
    
# Initial list
magicians = ['david copperfield', 'merlin', 'brozo']
print("This is the original list: ")
show_magicians(magicians)

# Dont modify the list, pass a copy
new_magicians = make_great(magicians[:])

# Show both lists.  First original
print("This is the original list: ")
show_magicians(magicians)

# New list
print("This is the new list: ")
show_magicians(new_magicians)
