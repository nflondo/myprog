def add(a, b):
    print "ADDING %d + %d" % (a, b)
    return a + b
    
def substract(a, b):
    print "SUBSTRACTING %d - %d" % (a,b)
    return a - b
    
def multiply(a,b):
    print "MULTIPLYING %d * %d" % (a,b)
    return a * b
    
def divide(a,b):
    print "DIVIDING %d / %d" % (a,b)
    return a / b
    
print "Let's do some math with just functions!"

age = add(30, 5)
height = substract(78, 4)
weight = multiply(90, 2)
iq = divide(100, 2)

print "Age: %d, Height: %d, Weight: %d, IQ: %d" % (age, height, weight, iq)

#A puzzle for extra credit
print "Here is a puzzle"

what = add(age, substract(height, multiply(weight, divide(iq,2))))

# Notice I don't need %d here.  it just prints the value of the variable.
# The commas are joining the two strings with the variable
print "That becomes: ", what, "Can you do it by hand?"                
