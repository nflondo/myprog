#!/usr/bin/env python3
import sys, timeit
# Similar to a list but cannot be changed.  Immutable.
# Working with tuples can be more efficient than lists, specialy with large data.
my_tuple = ("Max", 28, "Boston", "Boston") # parenthesis are optional
print(my_tuple)
# one element tuple is not a tuple, unless you add a comma at the end
my_tuple2 = ("Max")
print(type(my_tuple2))
my_tuple2 = ("Max",)
print(type(my_tuple2))

# Use tuple() to create one from a list
#my_tuple3 = tuple(["Max", 28, "Boston"])
my_tuple3 = tuple(my_tuple)
print(my_tuple3)
print(type(my_tuple3))

# Print items in tuple by index 0,1,2...-1 refers to last item, -2 second last...
item = my_tuple[2]
print(item)

# change elements is not possible, cause it's immutable
#my_tuple[0] = "Tim" # this returns an error

# Iterate over a tuple
for i in my_tuple:
    print(i)

# Check if element exists in tuple
if "Max" in my_tuple:
    print("Yes")
else:
    print("No")

# number of elements in the tuple
print(len(my_tuple))

# count certain elements in the tuple
print(my_tuple.count("Boston"))

# find index of an element
print(my_tuple.index(28))

# convert a tuple into a list
my_list = list(my_tuple)
print(my_list)
# convert it back, from list into tuple
my_tuple = tuple(my_list)
print(my_tuple)

# slicing tuple
a_tuple = (1,2,3,4,5,6,7,8,9,10)
b_tuple = a_tuple[2:5]
print(b_tuple)
# step
b_tuple = a_tuple[::3]
print(b_tuple)

# Unpacking
my_tuple = "Max", 18, "Boston"
name, age, city = my_tuple
print(name)
print(age)
print(city)
# Using asteriks to unpack
my_tuple = (0,1,2,3,4)
i1, *i2, i3 = my_tuple
print(i1)
print(i3)
print(i2)

# memory foot print
my_list = [0,1,2,"hello", True]
my_tuple = (0,1,2, "hello", True)
print(sys.getsizeof(my_list), "bytes") #takes more memory than tuple
print(sys.getsizeof(my_tuple), "bytes") # also more efficient to iterate over tuple

# timeit (working with tuples is more efficient than list)
print(timeit.timeit(stmt="[0,1,2,3,4,5]", number=1000000)) #one million times create list
print(timeit.timeit(stmt="(0,1,2,3,4,5)", number=1000000)) #on million times create tuple
