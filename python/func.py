#!/usr/bin/python
# demo function passing parameters by name and returning values

def print_total(customer_name, items):
    print "Total for {0}:".format(customer_name)
    total = 0
    for item in items:
        total = total + item
    print "${0}".format(total)

print_total(items=[5.0, 5.5, 5.0], customer_name="Alfred")

def get_square_and_cube(number):
    square = number * 2
    cube = number * 3
    return square,cube  # python will return a tuple that contains all the values returned by the function

result = get_square_and_cube(5)
print result

square, cube = get_square_and_cube(5) # the values are assign to my own vars
print square
print cube
