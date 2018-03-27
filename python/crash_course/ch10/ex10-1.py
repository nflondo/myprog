# 10-1

filename = 'learning_python.txt'
# reads entire file and prints entire file
with open(filename) as file_object:
    contents = file_object.read()
    print(contents)

# reads entire file prints it with a loop over the file object    
with open(filename) as file_object:
    for line in file_object:
        print(line.rstrip())
#        print(line)
print("--")

# reads and stores file in a list, then prints the list        
with open(filename) as file_object:
    lines_list = file_object.readlines()
    
for line in lines_list:
    print(line.rstrip())    
