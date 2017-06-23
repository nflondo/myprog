from sys import argv

script, input_file = argv

# read object file
def print_all(f):
    print f.read()

# rewind    
def rewind(f):
    f.seek(0)

# readline automatically advances to next line after being invoked    
def print_a_line(line_count, f):
    print line_count, f.readline(),  #comma here prevents print from adding \n
    ##rewind(current_file)

# open the file object, store it in current_file    
current_file = open(input_file)

print "First let's print the whole file:\n"

print_all(current_file)

print "Now, let's rewind, kind of like a tape."
rewind(current_file)

print "Let's print three lines:"
current_line = 1

print_a_line(current_line, current_file)

current_line += 1    

print_a_line(current_line, current_file)

current_line += 1    

print_a_line(current_line, current_file)
