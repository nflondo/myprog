#
# Lists of Numbers
#
# Using the range() function
for value in range(1,5):
	print(value) # Will print 1 -4, note it does not include 5
	
# Making a list from range with list()
numbers = list(range(1,6))
print(numbers)	

# start at 2, until it reaches 11, increase by 2
even_numbers = list(range(2, 11, 2))
print (even_numbers)

# Sample statistics
digits = [1,2,3,4,5,6,7,8,9,0]
min_digits= min(digits)
print(min_digits)

max_digit= max(digits)
print(max_digit)

sum_digits = sum(digits)
print(sum_digits)

# Creating a list with square values
squares = []
for value in range(1,11):
	squares.append(value**2)
	
print (squares)	

# List Comprehension
# Combines the for loop and creating list into one line
squares = [value**2 for value in range(1,11)]
print(squares)
