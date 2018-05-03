# 10-6 addition

while True:
	print("Enter two numbers to add")
	first_number = input("First number: ")
	second_number = input("Second number: ")
	try:
		result = (int(first_number) + int(second_number))
	except ValueError:
		print("Please only enter numbers")
	else:
		print("Result: " + str(result))
	again = input("Try again? (y/n) ")
	if again == 'n':
		break
	
