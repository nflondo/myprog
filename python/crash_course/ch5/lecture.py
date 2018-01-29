# checking for multiple conditions with "and"
age_0 = 22
age_1 = 18

if age_0 >= 21 and age_1 >= 21:
    print("both are > 21")
else:
    print("sorry, both are not > than 21")

# checking with "or"
if age_0 >= 21 or age_1 >= 21:
    print("One is > than 21")
else:
    print("sorry, neither is over 21")

# checking whether a value is in a list with "in"
toppings = ['mushroom', 'onions', 'pineapple']
if 'mushroom' in toppings:
    print("yes, mushroom is in toppings list")
else:
    print("not found in list")
    
# checking whether a value is NOT in a list with "not"
banned_users = ['andrew', 'carolina', 'david']
user = 'marie'
if user not in banned_users:
    print(user.title() + ", you can post if you wish.")
    
# conditionals
car = 'subaru'
print("is car == subaru? I predict True.")
print(car == 'subaru')

print("Is car == audi? I predict False.")
print(car == 'audi')

# if-elif-else chains.  Get evaluated in order.  Can use as many elif as
# you like.  else: at the end is optional.
# If more than one block of code needs to run, use a series of indepen-
#dent if statements.
age = 12
if age < 4:
    price = 0
elif age < 18:
    price = 5
else:
    price = 10    
    
print("Your admission cost is $" + str(price) + ".")    
