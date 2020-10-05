#!/usr/bin/env python3
# Function and Class decorators.  Function is more common.
# Allows to add functionality to an existing function
# Common use cases: implement exec time, debug, check if args fill req,
# register functions, cache return values, add info, or update state, 
#
#@mydecorator
#def dosomething(): # this function gets extended with functionality from decorator
#    pass
import functools
# Template for a decorator:
def start_end_decorator(func):

    @functools.wraps(func) # I believe this is needed to allow accept parameters
    def wrapper(*args, **kwargs): #allows parameters
        # before
        print('start...')
        result = func(*args, **kwargs)
        #after        
        print('End...')
        return result
    
    return wrapper


#@start_end_decorator // this works when decorator takes no arguments
#def print_name():
#    print('Nefi')

@start_end_decorator
def add5(x):
    return x + 5
#print_name()
#print_name = start_end_decorator(print_name) # same as @start_end_decorator
#print_name()
result = add5(10)
print(result)
print(help(add5))
print(add5.__name__)

