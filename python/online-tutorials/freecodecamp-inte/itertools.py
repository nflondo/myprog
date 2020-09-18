# itertools: can be used in for loops.  product, permutations, combinations
#accumulate, groupby, and infinite iterators.
# "Iterator in Python is any Python type that can be used with a ‘for in loop’. 
# Python lists, tuples, dictionaries, and sets are all examples of inbuilt iterators. "
# ( https://www.geeksforgeeks.org/python-itertools/ )
from itertools import product
from itertools import permutations
from itertools import combinations, combinations_with_replacement
from itertools import accumulate
from itertools import groupby
from itertools import count, cycle, repeat
import operator
a = [1,2]
b = [3]
prod = product(a,b)
print(prod)
print(list(prod))

prod = product(a,b, repeat=2) # repeat seems to make it so it randomly repeats prouducts
print(list(prod))

# permutations.  Return all possible ordering
a = [1,2,3]
perm = permutations(a)
perm = permutations(a,2)# specify the length of the permutation
print(list(perm))

# combinations.  All possible ombinations of specified length.  No repetitions.  No the
# same argument
a = [1,2,3,4]
comb = combinations(a,2)
print(list(comb))

# combinations with replacement
comb_wr = combinations_with_replacement(a, 2)
print(list(comb_wr))

# accumulate.  By default compute the sums.
acc = accumulate(a)
print(a)
print(list(acc))
acc = accumulate(a, func=operator.mul)
print(list(acc))
acc = accumulate(a, func=max)
print(list(acc))

# groupby function returns key from iterable
def smaller_than_3(x):
    return x < 3

a = [1,2,3,4]
#group_obj = groupby(a, key=smaller_than_3)
#print(group_obj)
#for key, value in group_obj:
    #print(key, value)
#    print(key, list(value)) # display True for values smaller than 3

# Lambda functions are small one line functions
#group_obj = groupby(a, key=lambda x: x<3)
#for key, value in group_obj:
    #print(key, value)
    #print(key, list(value)) # display True for values smaller than 3

# Define object persons.  Lists with dictionaries.
persons = [{'name': 'Tim', 'age':25},
            {'name': 'Dan', 'age':28},
            {'name': 'Lisa', 'age': 27},
            {'name': 'Claire', 'age': 25}
            ]            
group_obj = groupby(persons, key=lambda x: x['age'])# groups by age
for key, value in group_obj:
    #print(key, value)
    print(key, list(value)) # 

# infinite stuff.  Count
for i in count(10): # start value = 10, adds 1, it's infinite
    print(i)
    if i == 15:
        break

# cycle. infinite
a = [1,2,3]
#for i in cycle(a):  # repeats contents of the list
#    print(i)

# repeat
#for i in repeat(1): # infinite loop of ones 
for i in repeat(1, 4): # Will repeat 4 times
    print(i)
