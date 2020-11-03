#!/usr/bin/env python3
# Copy mutable elements with built in module.  and copies of custom objects
import copy
org = 5
cpy = org # this does not make a real copy, creates a new var pointing to same num
cpy = 6 # creates a new variable
print(cpy)
print(org)

org2 = [0,1,2,3,4]
cpy = org2
cpy[0] = -10
print(cpy)
print(org2)

# - shallow copy: one level deep, only references of nested child objects
# - deep copy: full independent copy

# shallow (the original is not affected)
orig = [1,2,3]
cpy = copy.copy(orig)
# cpy = orig.copy() # this also works
# cpy = list(orig) # this is possible
# cpy = orig[:] # this also makes an actual copy
cpy[0] = -10
print(cpy)
print(orig)

# nested list (deep copy), dict or tuple
orig3 = [[1,2,3], [4,5,6]]
cpy = copy.deepcopy(orig3) # original is not affected
cpy[0][1]= -10
print(cpy)
print(orig3)




