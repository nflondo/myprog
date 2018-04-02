# 10-3
user_name= input("Please tell me your name: ")

filename = 'guest.txt'
with open(filename, 'w') as file_object:
    file_object.write(user_name + '\n')
