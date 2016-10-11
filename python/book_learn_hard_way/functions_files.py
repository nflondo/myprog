#!/usr/bin/python
# 
from sys import argv

# argv takes the parameters passed to the script from cmd line 
# and assigns it to variables "script" and "input_file"
script, input_file = argv

def print_all(f):
    print f.read()

# seek number is bytes. One letter = 1 byte
def rewind(f):
    f.seek(1)

# Comma at the end avoids printing extra \n 
def print_a_line(line_count, f):
    print line_count, f.readline(),

current_file = open(input_file)

print "First let's print the whole file:\n"

print_all(current_file)

print "Now let's rewind, kind of like a tape."

# file has to be rewund to print from beginning again
rewind(current_file)

print "Let's print three lines:"

# current_line is an arbitrary number only useful to 
# show what line we're on the file
current_line = 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)
