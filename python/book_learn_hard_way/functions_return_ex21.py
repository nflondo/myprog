#!/usr/bin/python
#   

def add(a, b):
    print "ADDING %d + %d" % (a, b)
    return a + b

def subtract(a, b):
    print "SUBTRACTING %d - %d" % (a, b)
    return a - b

def multiply(a, b):
    print "MULTIPLYING %d * %d" % (a, b)
    return a * b

def divide(a, b):
    print "DIVIDING %d / %d" % (a, b)
    return a / b

def mycomparison(a,b):
    print "Comparing %d and %d" % (a,b)
    if a > b:
        print "A > B"
        return "A"
    elif b > a:
        print "B > A"
        return "B"
    else:
        print "A and B must be equal"
        return "Equal"        
    

print "Let's do some math with just functions!"

num_1 = int(raw_input("Please give me first number:  "))
print "Type: ",
print (type(num_1))
#age = add(30, 5)
age = add(num_1, 5)
height = subtract(78, 4)
weight = multiply(90, 2)
iq = divide(100, 2)

print "Age: %d, Height: %d, Weight: %d, IQ: %d" % (age, height, weight, iq)


# A puzzle for the extra credit, type it in anyway.
print "Here is a puzzle."

# The return value of a function, can be used as the input to another
# function
what = add(age, subtract(height, multiply(weight, divide(iq, 2))))

print "That becomes: ", what, "Can you do it by hand?"

# This is a silly test for a return string
compare_result = mycomparison(20,20)
print "compare_result: %s" % compare_result
