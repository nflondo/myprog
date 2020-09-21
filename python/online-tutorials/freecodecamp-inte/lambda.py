#!/usr/bin/env python3
#lamba is a one line function defined without a name
# Useful when you need a function once or when need to pass a function to another
# function.  Used along with builtin function sorted, map, filter, reduce
# lambda arguments:expression
from functools import reduce
add10 = lambda x: x + 10 # this is a function with one argument.  
print(add10(5))
# above lambda is the same as this:
def add10_func(x):
    return x + 10

mult = lambda x,y: x * y
print(mult(2,7))
# sorted method
points2D = [(1,2), (15,1),(5, -1),(10,4)]
points2D_sorted = sorted(points2D, key=lambda x: x[1]) # sorts list on the y element
                                    # lambda function returns arg[1] of the tuple
# this is the function equivalent of the lambda above
def sort_by_y(x):
    return x[1]
with_function = sorted(points2D, key=sort_by_y)
print(with_function)
points2D_def_sort = sorted(points2D) # 

print(points2D) # [(1, 2), (15, 1), (5, -1), (10, 4)]
print(points2D_def_sort)
print(points2D_sorted)# prints: [(5, -1), (15, 1), (1, 2), (10, 4)]

# sort according to their sum
sort_by_sum = sorted(points2D, key=lambda x: x[0] + x[1])
print(sort_by_sum)

##Map function
#map(func, seq)
a = [1,2,3,4,5]
b = map(lambda x: x*2, a)
print(list(b))
# same as map above: (easier to read actually than a map)
c = [x*2 for x in a] # multiplies each element in the list by 2
print(c)
## Filter
# filter(func, seq) # returns all elements that func evalutes to true
a = [1,2,3,4,5,6]
b = filter(lambda x: x%2==0, a)
print(list(b))
# same as above but with list comprehension
c = [x for x in a if x%2==0]
print(c)
## reduce
# reduce(func, seq)
a = [1,2,3,4]
product_a = reduce(lambda x,y: x*y, a)
print(product_a)# result: 24