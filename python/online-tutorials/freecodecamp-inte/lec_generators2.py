#!/usr/bin/env python3
import sys
def firstn(n):
    nums = []
    num = 0
    while num < n:
        nums.append(num)
        num += 1
    return nums

#print(sum(firstn(10))) # This take a lot of memory
print(sys.getsizeof(firstn(10))) # returns size in bytes

# implement the above as generator object.  No need for a list.
def firstn_generator(n):
    num = 0
    while num < n:
        yield num
        num += 1

#print(sum(firstn_generator(10)))
print(sys.getsizeof(firstn_generator(10))) #returns size in bytes
