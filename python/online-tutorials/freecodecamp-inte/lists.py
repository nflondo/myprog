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
item = mylist.clear()
print(mylist)

#min 7:57