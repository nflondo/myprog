#!/usr/bin/env python3
# mutable, key-value pairs
# Key types can be: numbers, tuples, strings
my_dict = {"name": "Max", "age": 28, "city": "New York"}
print(my_dict)
# create a dictionary via function dict()
my_dict2 = dict(name="Mary", age=27, city="Boston")
print(my_dict2)
# Access values
value = my_dict2["name"]
print(value)

# Add items to dictionary
my_dict["email"] = "max@xyz.com"
print(my_dict)

# Delete items
del my_dict["name"]
print(my_dict)
# delete using pop
my_dict.pop("city")
print(my_dict)
my_dict.popitem() # since 3.7 it removes the last item
print(my_dict)
# find items
if "name" in my_dict2:
    print(my_dict2["name"])
# using try except
try:
    print(my_dict2["name"])
except:
    print("Error")
# print dictionary keys
for key in my_dict2: # or for key in mydict.keys()  # which returns a list with the keys
    print(key)
# print dic values
for value in my_dict2.values():
    print(value)
# print both keys and values
for key, value in my_dict2.items():
    print(key, value)
# Copy a dict
mydict_copy = my_dict2 # but if modify copy tne modify original
# Copy an independent copy
mydict_real_copy = my_dict2.copy()
print(mydict_real_copy)
# copy using dict function
sec_real_copy = dict(my_dict2)
sec_real_copy["house"] = "mansion"
print(sec_real_copy)
print(my_dict2)
# Merge two dictionaries
dict3 = {"name": "Max", "age":28, "email":"my@xyz.com"}
dict4 = dict(name="Mary", age=27, city="Boston")

dict3.update(dict4) # existing keys in dict3 will get overwritten with values in dict4
print(dict3)
# Key types: numbers, tuples, strings
dict5 = {3:9, 6:36, 9:81}
print(dict5)
value = dict5[6]
print(value)
# Use a tuple as a key
mytuple = (8,7)
dict6 = {mytuple: 15}
print(dict6)
