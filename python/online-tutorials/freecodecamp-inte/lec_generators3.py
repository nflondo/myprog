#!/usr/bin/env python3
def fibonacci(limit):
    # 0 1
    # sum of the previous two numbers
    #0 1 1 2 3 
    a, b = 0, 1
    while a < limit:
        yield a
        a, b = b, a + b

fib = fibonacci(30)
for i in fib:
    print(i)

# generator expressions.  Similar to list comprehension but with parenthesis instead
# of square brackets.
mygenerator = (i for i in range(10) if i % 2 == 0)
for i in mygenerator:
    print(i)

mylist = [i for i in range(10) if i % 2 == 0]
print(mylist)

# Convert a generator object to a list
print(list(mygenerator))



