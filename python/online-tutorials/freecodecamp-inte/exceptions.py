#!/usr/bin/env python3
##Exceptions and Errors.  A python program terminates as soon as it encounters 
# error (syntax or exception)
# will cause syntax error# a = 5 print(a)
# exception error
# type error # a = 5 + '10'
# import error
# import somemodule
#a = 5
#b = c
# file not found
#f = open('somefile.txt')
a = [1,2,3]
a.remove(1)
print(a)
#a.remove(4) # error not in list

## Exceptions
x = -5
#if x < 0:
#    raise Exception('x should be positive') #exception and quitss
# assertion error
#assert(x >=0) #error if assertion is not true
#assert (x>=0), 'x is not positive' #with a message after error
try:
    a = 5 / 0
except:
    print('an error happened') # program continues
print('program continuing...')
# Catch the type of exception:
try:
    a = 5 / 0
except Exception as e:
    print(e)
print('program continuing again...')
# Be more specific if you can.  It will only print one of the exceptions. The
# first one it finds.
try:
    a = 5 / 0 # 5 / 0
    #b = a + '10'   
except ZeroDivisionError as e:
    print(e)
except TypeError as e:
    print(e)
else: # if no exception occurs
    print('everything is fine')
finally: # runs always, regarding if it found exception or not, for cleanup
    print('cleaning up')
print('program continuing 3...')
## Define our own exception, by sub-classing from base exception class
class ValutTooHighError(Exception):
    pass

class ValueTooSmallError(Exception):
    def __init__(self, message, value):
        self.message = message
        self.value = value 

def test_value(x):
    if x > 100:
        raise ValutTooHighError('value is too high')
    if x < 5:
        raise ValueTooSmallError('value too small', x)
try:
    #test_value(200)
    test_value(1)
except ValutTooHighError as e:
    print(e)
except ValueTooSmallError as e:
    print(e.message, e.value)
print('program continuing 4...')


