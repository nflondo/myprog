# 10-5

filename='responses_ex10-5.txt'
while True:
    user_response= input("Why do you like programming? ")    
    if user_response != "":
        with open(filename, 'a') as file_object:
            file_object.write(user_response + '\n')
    else:
        print("Adding nothing to file")
            
    add_name= input("Add another response? [y/n]: ")
    if add_name == 'n':
        break
    
