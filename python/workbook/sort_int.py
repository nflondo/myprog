#!/usr/bin/python3
# Read 3 ints from user, and display them in sorted order
# use built-in function min() and max()

numbers = input("Enter 3 numbers (no spaces in between): ")
if len(numbers) == 3 :     
    min_number = min(int(numbers[0]), int(numbers[1]), int(numbers[2]))
    max_number = max(int(numbers[0]), int(numbers[1]), int(numbers[2]))
    middle_num = ((int(numbers[0]) + int(numbers[1]) + int(numbers[2])) - 
        min_number - max_number)
else :
    print("Please enter 3 numbers")

#print("Min number: %d" % min_number)
print("Sorted numbers: %d %d %d" % (min_number, middle_num, max_number))
