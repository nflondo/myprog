#!/usr/bin/python
# random function from random module will never return zero or one

from random import random

#mylist = {}
zero =0
one =0
othernum =0
for i in range(10): 
    num = random() 
  
    if num == 0:
        zero = zero +1
    elif num ==1:
        one = one +1
    else:
        othernum = othernum +1

print "Zero: {0}; One: {1}; Other: {2}".format(zero, one, othernum)
