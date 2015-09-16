#!/usr/bin/python
# random function from random module will never return zero or one

from random import random

#mylist = {}
zero =0
one =0
othernum =0
counter = 0
for i in range(50): 
    num = random() 
    counter = counter +1
    if num == 0:
        zero = zero +1
    elif num ==1:
        one = one +1
    else:
        othernum = othernum +1
        print num

print "Zero: {0}; One: {1}; Other: {2} Counter: {3}".format(zero, one, othernum, counter)
