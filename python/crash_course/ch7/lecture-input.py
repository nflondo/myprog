# input() python considers everything entered a String
message = input("Tell me something: ")
print(message)

# long text, then prompt
prompt = ("If you tell us who  you are, we can personalize the messages" 
    " you see.  This way is more personal.  Understand?")
prompt += "\nWhat is your first name? "

name = input(prompt)
print("\nHello, " + name + "!")    

# int() for numerical input
height = input("How tall are you, in inches? ")
height = int(height)

if height >= 36:
    print("\nYou're tall enough to ride!")
else:
    print("\nYou'll be able to ride when you're older")
    
# Modulo operator.  Even or odd numbers
number = input("Enter a number: ")
number = int(number)

if number % 2 == 0:
    print("\nThe number " + str(number) + " is even.")
else:
    print("\nThe number " + str(number) + " is odd.")
    
