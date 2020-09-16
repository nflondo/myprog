#!/usr/bin/env python3
mylist = ["banana", "cherry", "apple"]
print(mylist)
# create new empty list
mylist_empty = list()
print(mylist_empty)
#different data types and duplicate elements are allowed
mylist2 = [5, True, "apple", "apple"] 
print(mylist2)

# get elements by index numbers
item = mylist[0]
print(item)
# negative number refers to the last item in the list, -2 = second to last
item = mylist[-1]
print(item)

item = mylist[-2]
print(item)

#iterate over list
for i in mylist:
    print(i)

# check if item in the list
if "banana" in mylist:
    print("found")
else:
    print("not found")

#number of elements in the list
print(len(mylist))

#append items to list
mylist.append("lemon")
print(mylist)

# insert item at specific position, then item
mylist.insert(1, "blueberry")
print(mylist)

# remove last item from list
item = mylist.pop()
print(item)
print(mylist)

# remove specific element
item = mylist.remove("banana")
print(mylist)

# remove all elements in list
#item = mylist.clear()
#print("mylist.clear():" ,mylist)

# Reverse a list
#item = mylist.reverse()
#print(mylist)
#min 7:57

# sort list
mylist3 = [4, 3, 1, -1, -5, 10]
print(mylist3)
item = mylist3.sort()
print(mylist3)

# create a list via multiplication of an element
mylist4 = [0] * 5 #will create [0, 0, 0, 0, 0]
print(mylist4)

# Combine two lists into one
mylist5 = mylist + mylist3
print(mylist5)

# Slicing a list
mylist6 = [1,2,3,4,5,6,7,8,9]

a = mylist6[1:5] # start index is 1 and stop index is 5. Result: [2, 3, 4, 5]
                # stop index not included in the results
print(a)
a = mylist6[:5] # No start index means start from beginning
print(a)
# Step through a list
a = mylist6[::2] #from beginning to the end step every second item:[1, 3, 5, 7, 9]
print(a)

# copying a list
list_org = ["banana", "cherry", "oranges"]
list_cpy = list_org.copy() # allows to modify copy without altering original
list_cpy.append("pineapple")
print(list_cpy)
print(list_org)
# Fast, elegant way to create a new list from existing list (list comprehension)
b_list = [1,2,3,4,5,6]
c = [i*i for i in b_list] # [expression for loop over list]
print(b_list)
print(c)
