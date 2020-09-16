#!/usr/bin/env python3
# Set is a collection data type that is unordered, mutable, no duplicates

myset = {1,2,3}
#print(myset)
# use set function
set_2 = set([4,5,6]) # use a list
#print(set_2)
set_3 = set("Hello") # use a string
#print(set_3) # this print with characters in random order

# add elements
myset.add(4)
myset.add(5)
#print(myset)
# remove elements
myset.remove(3)
#print(myset)
# empty set with clear()
myset.clear()
#print(myset)
# pop() return arbitrary value and removes it
#print(set_2.pop())
#print(set_2)
# iterate over set
for i in set_2:
    print(i)
# is element?
if 5 in set_2:
    print("yes")
else:
    print("no")
# union (combines elements from two sets without duplicates) and intersection 
# (only elements found in both sets)
odds = {1,3,5,7,9}
evens = {0,2,4,6,8}
primes = {2,3,5,7}

u = odds.union(evens)
#print(u)

i = odds.intersection(primes)
#print(i)

# Difference of two sets (returns all elements in the first set that are not in
# the second set)
setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
diff = setA.difference(setB)
#print(diff)
# Symmetric difference returns all elements in set a and b but not elements in
# both sets
diff2 = setB.symmetric_difference(setA)
print(diff2)
diff_3 = setA.symmetric_difference(setB)
#print(diff_3) # returns the same result as above
# Modify sets in place.  Add the elements found in second set
setA.update(setB)
#print(setA)
setA.intersection_update(setB)# updates the sets by keeping only the elements found
                                # in both sets
#print(setA)                                
# difference_update.  Removes element found in another set
setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
setA.difference_update(setB)
#print(setA)
# symmetric difference update.  Does not keep elements found in both sets
setA = {1,2,3,4,5,6,7,8,9}
setB = {1,2,3,10,11,12}
setA.symmetric_difference_update(setB)
#print(setA)
# sub-sets.  Are all elements of first set in the second set? boolean
setA = {1,2,3,4,5,6}
setB = {1,2,3}
setC = {7,8}
#print(setA.issubset(setB))
# super-set is the opposite of sub-set
#print(setA.issuperset(setB))
# disjoint (no interception between sets) null interception
print(setA.isdisjoint(setB))
print(setA.isdisjoint(setC))
# Copying two sets
setB = setA.copy()
# Frozen set (it's an immutable set)
a = frozenset([1,2,3,4])
print(a)