#!/usr/bin/env python3
result = 5 * 7 
print(result)

result = 2 ** 4 # two to power of 4
print(result)

zeros = [0] * 10 # creates a list with 10 elements each 0
print(zeros)

zeros = [0,1] * 10 # repeats 0 and 1 ten times
print(zeros)

zeros = (0, 1) * 10 # works with tuples

zeros = "AB" * 10 # creates a new string with 10 times AB
print(zeros)

def foo(a,b, *args, **kwargs): #takes any number of args and kwargs
    print(a, b)
    for arg in args:
        print(arg)
    for key in kwargs:
        print(key, kwargs[key])

foo(1,2, 5,6,7, six=6, eight=8)

def soo(a,b, *, c): # all parameters after * are keyword only parms
    print(a,b,c)
soo(1,2, c=8) # c is required here and is keyword parm

def buu(a,b,c):
    print(a,b,c)
my_list = [0,1,2] # number of elements must match number of parameters in buu
                    # also works with a tuple
buu(*my_list) # unpacks my list into arguments

my_dict = {'a':9, 'b':8, 'c':12} # number of elements must match num of paremeters
                    # and dict keys must match parameters's name
buu(**my_dict) #unpack dictionary here, 

numbers = [1,2,3,4,5,6]
*beginning, last = numbers #unpacks all elements except the last one into a list
                # last element goes into its own variable
print(beginning)
print(last)

beginning, *last = numbers #unpacks first into a var, rest into a list
print(beginning)
print(last)

beginning, *middle, secondlast, last = numbers # more assignments
print(beginning)
print(middle)
print(secondlast)
print(last)

my_tuple = (1,2,3)
my_list = [4,5,6]

new_list = [*my_tuple, *my_list] # merges the tuple and the list into a list
print(new_list) 

my_tuple = (1,2,3)
my_set = {4,5,6}

new_list = [*my_tuple, *my_set]
print(new_list)

dict_a = {'a':1, 'b':2}
dict_b = {'c':3, 'd': 4}
new_dict = {**dict_a, **dict_b}
print(new_dict)




