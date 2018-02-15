# while loops
current_number = 1
while current_number <= 5:
    print(current_number)
    current_number += 1
    
prompt = ("If you tell us who  you are, we can personalize the messages" 
    " you see.  Enter 'quit' to end this program")
prompt += "\nWhat is your first name? "

message = ""
while message != 'quit':
    message = input(prompt)
    print(message)    

# Using a flag
prompt = "\nTell me something and I'll repeat it back to you."
prompt += "\nEnter 'quit' to end the program: "

active = True
while active:
    message = input(prompt)
    
    if message == 'quit':
        active = False
    else:
        print(message)

# break allow to quit immediately in any of python loops.
# continue returns to the beginning of the loop
