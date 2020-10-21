#!/usr/bin/env python3
"""
- The difference between arguments (passed when calling) and parameters 
(when defining a funct)
- Positional and keyword arguments
- Default arguments
- Variable-length arguments(*args and **kwargs)
- Container unpacking into function arguments
- Local vs global arguments
- Parameter passing (by value or by reference)
"""
# Positional and default (must be at the end of paremter list in func)
def foo(a,b,c, d=4):
    print(a, b, c, d)

foo(1,2,3)
# keyword.  Order not important
foo(a=1, b=2, c=3)
# mix of both
foo(1, b=2, c=3) #cannot use another position arg after using keyword arg
#default argument
foo(1,2,3,7)

# variable length arg
# *args/or any name allows to pass any number or arguments. It's a tuple.
# **kwargs/or any name allows to pass any number of keyword arguments. It's a dict
def var_length(a,b, *args, **kwargs):
    print(a,b)
    for arg in args:
        print(arg)
    for key in kwargs:
        print(key, kwargs[key])

var_length(1,2, 3,4,5, six=6, seven=7)
var_length(1,2, 3) # this is valid

# Enforce keyword arguments.  Everything after * must be a kwarg
def bah(a,b, *, c,d):
    print(a,b,c,d)

bah(1,2,c=3,d=4)

#another example.  It enforces last parameter as keyword arg
def buh(*args, last):
    for arg in args:
        print(arg)
    print(last)

buh(1,2,3, last=100)

# Unpacking arguments
def funp(a,b,c):
    print(a,b,c)

my_list = [0,1,2] # or tuple here. length must match number of parameters in func
funp(*my_list) # unpacks first element into a, second into b, third into c, etc
# Using a dictionary to unpack
my_dict = {'a':1, 'b':2, 'c':3} # dict keys must be the same name as parameters in func
funp(**my_dict)