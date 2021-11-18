#!/usr/bin/python3
# Read 3 ints from user, and display them in sorted order
# use built-in function min() and max()

user_input = input("Enter 3 numbers (separated by a space): ")
list_num = user_input.split() #splits on space by default
#print("list_num: ", list_num)
if len(list_num) == 3 :
    min_number = min(int(list_num[0]), int(list_num[1]), int(list_num[2]))    
    max_number = max(int(list_num[0]), int(list_num[1]), int(list_num[2]))
    middle_num = ((int(list_num[0]) + int(list_num[1]) + int(list_num[2])) -
        min_number - max_number)
else :
    print("Please enter exactly 3 numbers")

#print("Min number: %d" % min_number)
print("Sorted numbers: %d %d %d" % (min_number, middle_num, max_number))
