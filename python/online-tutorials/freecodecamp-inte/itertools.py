# itertools: can be used in for loops.  product, permutations, combinations
#accumulate, groupby, and infinite iterators.
from itertools import product
from itertools import permutations
a = [1,2]
b = [3, 4]
prod = product(a,b)
print(prod)
print(list(prod))

prod = product(a,b, repeat=2)
print(list(prod))

a = [1,2,3]