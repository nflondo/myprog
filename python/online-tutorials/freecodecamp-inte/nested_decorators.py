#!/usr/bin/env python3
import functools

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

def debug(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        args_repr = [repr(a) for a in args]
        kwargs_repr = [f"{k}={v!r}" for k, v in kwargs.items()]
        signature = ", ".join(args_repr + kwargs_repr)
        print(f"Calling {func.__name__}({signature})")
        result = func(*args, **kwargs)
        print(f"{func.__name__!r} returned {result!r}")
        return result
    
    return wrapper

# Stacked decorators are executed in the order they're listed
@debug 
@start_end_decorator
def say_hello(name):
    greeting = f'Helo {name}'
    print(greeting)
    return greeting

say_hello('Oscar')