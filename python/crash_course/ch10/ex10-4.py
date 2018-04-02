# 10-4

filename='guest_book.txt'
while True:
    user_name= input("Please tell me your name: ")
    print("Welcome " + user_name)
    with open(filename, 'a') as file_object:
        file_object.write(user_name + '\n')
        
    add_name= input("Add another user? [y/n]: ")
    if add_name == 'n':
        break
    
