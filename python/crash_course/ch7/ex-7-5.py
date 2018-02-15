# Movie tickets

response = ""
while response != 'q':
    prompt = "What's your age? (Enter 'q' to end)"
    age = input(prompt)
    if age == 'q':
        print("Good bye")
        break
        
    age = int(age)
    
    if age < 3:
        print("Your ticket is free")
    elif age < 12:
        print("Your ticket is $10")
    elif age > 12:
        print("Your ticket is $15") 
