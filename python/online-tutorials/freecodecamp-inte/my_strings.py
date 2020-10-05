#!/usr/bin/env python3
from timeit import default_timer as timer
# Strings: ordered, immutable, text representation
# Either single or double quotes.  single quotes more common
#double quotes
#my_string = "Hello World"
#single quote
#my_string = 'I\'m a programmer'
# multi-line
my_string = """Hello \
World
"""
print(my_string)

my_2string = "hello World"
char = my_2string[0]
print(char)
char = my_2string[1]
print(char)
char = my_2string[-1] # last character
print(char)

#sub-string with slicing
substring = my_2string[1:5] #[::2] every second character #[::-1] reverse string
print(substring)
#concatenate
name = 'Tom'
sentence = name + " " + my_2string
print(sentence)

for i in name:
    print(i)

if 'e' in name: # if 'om' in name:  is valid as well
    print('yes')
else:
    print('no')

my_3string = '     Hello World'
print(my_3string)
my_3string = my_3string.strip() # removes the white space, this assignment changes original string
# otherwise, original string remains the same
print(my_3string)

#convert to uppercase/lower
print(my_3string.upper())
print(my_3string.lower())

# check if starts with certain char
print(my_3string.startswith('He'))

# ends with something
print(my_3string.endswith('ld'))

# find index of a char
print(my_3string.find('o')) # returns first index with an 'o'
# check for substring start.  Returns -1 if not found
print(my_3string.find('Wo'))
# count number of chars or subs
print(my_3string.count('o'))
# replace characters inside the string
print(my_3string.replace('World', 'Universe')) #returns new string, doesn't change original
# if sstring not found, it does nothing

# Lists and strings
my_4string = 'how are you doing' # convert to a list, default delimiter is a space
my_list = my_4string.split()
print(my_list)
# other delimiter
my_5string = 'how, are, you'
my_list = my_5string.split(',')
print(my_list)
# convert list into a string
new_string = ''.join(my_list)
print(new_string)

my_2list = ['a'] * 6 # creates a list with 6 elements
print(my_2list)
# bad python code
start = timer()
my_string = ''
for i in my_2list:
    my_string += i # expensive operation
stop = timer()
print(stop - start)
print(my_string)
# good
start = timer()
my_string = ''.join(my_2list)
stop = timer()
print(stop - start)
print(my_string)

# Formatting Strings
# Old style is with % or .format method.  Since python 3.6 f-String
var = "Tom"
my_string = "the variable is %s" % var #place holder then variable
print(my_string)

var2 = 3
my_string = "the variable is %d" % var2 #place holder then variable
print(my_string)

var3 = 3.141621
my_string = "the variable is %f" % var3 #place holder then variable (6 digits by default)
#my_string = "the variable is %.2f" % var3 #
print(my_string)

# still old formatting
var4 = 6
my_string = "the variable is {}".format(var3)
my_string = "the variable is {:.2f}".format(var3) # 2 digits
my_string = "the variable is {:.2f} and {}".format(var3, var4) # 2 digits
print(my_string)

# new formatting since python 3.6
my_string = f"new format - the variable is {var3} and {var2}"
my_string = f"new format - the variable is {var3*2} and {var2}"
print(my_string)

list2 = ['zorro']
print('list2' + ''.join(list2))



