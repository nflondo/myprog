# 10-2

# Reading one line at a time
filename = 'learning_python.txt'

with open(filename) as file_object: 
    lines = file_object.readlines()
    
for line in lines:
    line = line.strip()
#    line.replace('Python', 'C')  # this doesn't work
#    print(line)
    print(line.replace('Python','C'))


