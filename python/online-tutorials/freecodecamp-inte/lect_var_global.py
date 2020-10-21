# global variables
number = 0

def foo():
    #x = number  # this errors out cause can't modify a global variable locally
    global number # this will work cause is calling the global var
    x = number
    number = 3
    print('number inside fuction', x)

foo()
print(number)

# Parameter passing. Call by value or by reference. 
# In python call by object reference

def boo(x):
    x = 5

var = 10 #immutable var so can't be changed in func
boo(var)
print(var)

# Mutable objects (such as lists) can be modified
def buu(a_list):
    a_list.append(4) # local var
    a_list[0] = -100 # list at index 0

my_list = [1,2,3]
buu(my_list)
print(my_list)

def goo(a_list):
    a_list = [200,300,400]

goo(my_list)
print(my_list) # still prints original list

def moo(a_list):
    a_list += [200,300,400]  # this changes original list, appends to it
    #a_list = a_list + [200,300,400] #this will create a new var, so not change
    # original list

moo(my_list)
print(my_list)


