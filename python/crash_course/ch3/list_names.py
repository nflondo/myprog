friends = [ 'gero', 'memo', 'raul', 'anna' ]

for friend in friends:
	print("Good to see you " + friend.title() + "!")
	
# Appending to a list (at the end)
friends.append('fernando')
print(friends)

# It's common to start with an empty list and append later
empty_list = []
empty_list.append('ford')
empty_list.append('mercedes bens')
print(empty_list)

# Inserting elements into a list with insert()
empty_list.insert(0, 'jaguar')
print(empty_list)

# Removing item from list with "del" statement
del empty_list[0]
print(empty_list)

# Removing using pop() from end of the list or at any position by specifying
# and index.
popped_item = friends.pop()
print("Printing after pop: " + str(friends))
print(popped_item)

second_item = friends.pop(1)
print(second_item)

# Removing an item by value using remove() from any position in the list
# it removes only one  occurrence
friends.remove('raul')
print(friends)
	
