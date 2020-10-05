#!/usr/bin/env python3
# Functions that return an object that can be iterated.
# More memory efficient that other sequence objects whe dealing with large
# data sets.
# Values returned by generator can only be read once
def mygenerator():
    yield 3 # keyword used like return, but returns a generator
    yield 2
    yield 1

g = mygenerator()
#print(g)

#for i in g:
#    print(i) # prints 1 2 3

#print(sorted(g))
#print(sum(g))

'''
value = next(g)
print(value)

value = next(g)
print(value)

value = next(g)
print(value)
'''
#value = next(g) # raises stop operation
#print(value)

def countdown(num):
    print('Starting')
    while num > 0:
        yield num
        num -= 1

cd = countdown(4)

value = next(cd) # next will make it remember current state
print(value)

print(next(cd))


