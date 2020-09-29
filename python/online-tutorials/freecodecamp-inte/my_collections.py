#!/usr/bin/env python3
# Collections: Counter, namedtuple, orderedDict, defaultdict, deque
# container that stores elements as keys and values

#print (dir(collections)) # View all functions of the module
#print (dir(timeit)) # View all functions of the module

#Read more about it with help
#help(math.factorial)
# https://towardsdatascience.com/pythons-collections-module-high-performance-container-data-types-cb4187afb5fc
from collections import Counter #stores elements as dictionary keys and their count as
from collections import namedtuple # lightweight object type similar to a struct
from collections import OrderedDict# dictionary that remembers order items were inserted
from collections import defaultdict# dictionary that will have a default value
from collections import deque# it's a double ended queue used to add/remove elements from both ends
# values
a = "aaaaabbbcccccc" # this can be a list too
my_counter = Counter(a)
'''
print(type(my_counter))
print(my_counter) # prints: Counter({'c': 6, 'a': 5, 'b': 3})
print(my_counter.items())
print(my_counter.keys())
print(my_counter.values())
print(my_counter.most_common(1)) # print the most common one (2) will return 2 most common
print(my_counter.most_common(1)[0][0])# returns only the most common key
print(list(my_counter.elements())) # returns all elements as a list
'''
Point = namedtuple('Point', 'x,y') # (Classname, fields )
pt = Point(1, -4)
print(pt)
print(pt.x, pt.y)

ordered_dict = OrderedDict()

ordered_dict['b'] = 2
ordered_dict['c'] = 3
ordered_dict['d'] = 4
ordered_dict['a'] = 1
print(ordered_dict)

d = defaultdict(int) # Assigns a default value 0 of type int to keys without a value yet
# default value type can be: float, list, 
d['a'] = 1
d['b'] = 2
print(d)
print(d['a'])
print(d['b'])
print(d['c']) # returns default value which is 0 and int.

e = deque()
e.append(1)
e.append(2)
e.appendleft(3)
e.pop() # removes last element in list
e.popleft()
#e.clear()
e.extend([4,5,6])
e.extendleft(['a','b','c'])
print(e)
e.rotate(1) # rotate one place to the right
e.rotate(-1) # rotate one place to the left
print(e)



 