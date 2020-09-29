#!/usr/bin/env python3
# built in modules for random numbers
import random
import secrets # for security
import numpy as np # this has to be installed with pip

a = random.random() # random float in rage from 0 -1
b = random.uniform(1,10) # random float in range given
c = random.randint(1,5) # includes upper bound
print(a)
print(b)
print(c)
d = random.normalvariate(0,1)#pick random from normal distribution with mean=0
#and standard deviation = 1

#sequences
mylist = list("ABCDE")
e = random.choice(mylist) # chooses a random element from the list
print(e)
f = random.sample(mylist, 3)#picks unique elements
print(f)
g = random.choices(mylist, k=3) #multiple times
print(g)

random.shuffle(mylist) # shuffles the list in place
print(mylist)

random.seed(1) # makes the random numbers reproducible
print(random.random())
print(random.randint(1,10))
random.seed(1) # makes numbers reproducible
print(random.random()) # same numbers as above
print(random.randint(1,10)) # same numbers as above

# passwords, security tokens (it takes more time, but gen true random num)
a = secrets.randbelow(10) #random int from 0 - 9
print(a)
b = secrets.randbits(4) #return an int with k bits 1010
print(b)

myl = list("EFGHI")
c = secrets.choice(myl)
print(c)

# arrays
d = np.random.rand(3) # creates an array with 3 elements
print(d)
e = np.random.rand(3,3) # creates a 2D array, 3 x 3
print(e)
f = np.random.randint(0, 10, 3) # 10 excluded, create array size = 3
print(f)

g = np.random.randint(0, 10, (3,4)) #tuple creates 2D array 
print(g)

arr = np.array([[1,2,3], [4,5,6], [7,8,9]])
print(arr)

np.random.shuffle(arr) #shuffles array in first axis not in between
print(arr)

np.random.seed(1)
print(np.random.rand(3,3))
np.random.seed(1)
print(np.random.rand(3,3))




