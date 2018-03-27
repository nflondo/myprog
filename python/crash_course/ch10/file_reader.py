# open function returns an object which gets stored in file_object 
# keyword "with" closes the file automatically when it's no longer needed 
# read() reads entire contents of the file (one long string)            
"""
with open('pi_digits.txt') as file_object:
    contents = file_object.read()
    print(contents)
    # or without a blank line at the end (right side)
    print(contents.rstrip())
"""
"""
# Reading one line at a time
filename = 'pi_digits.txt'

with open(filename) as file_object:
    for line in file_object:
        print(line.rstrip())
        
"""
"""
# Making a list of lines from a file
# readlines() method takes each line from a file and stores it in a list
filename = 'pi_digits.txt'

with open(filename) as file_object:
    lines = file_object.readlines()
    
for line in lines:
    print(line.rstrip())
"""
# working with file contents
# Note: when pythong reads in a file, it interprets the file as a string
#filename='pi_digits.txt'
filename='pi_million_digits.txt'
with open(filename) as file_object:
    lines = file_object.readlines()
    
pi_string=''
for line in lines:
    pi_string += line.strip()

birthday = input("Enter your birthday, in the form mmddyy: ")
if birthday in pi_string:
    print("Your birthday appears in the first million digits of pi!")
else:
    print("Your birthday does not appear in the first million digits of" +
    "pi.")
    
#print(pi_string)
print(pi_string[:52] + "...")
print(len(pi_string))

# Large file
