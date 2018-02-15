# Lecture while lists and dictionaries
# Don't use for loops to modify a list, use while loops

unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

# Remove users from unconfirmed and into confirmed lists
while unconfirmed_users:
    current_user = unconfirmed_users.pop()
    
    print("Verifying user: " + current_user.title())
    confirmed_users.append(current_user)
    
print("\nThe following users have been confirmed:")
for user in confirmed_users:
    print(user.title())

# Removing multiple instances of a specific value in a list
pets = ['dog', 'cat', 'fish', 'cat', 'rabbit', 'cat']
print(pets)

while 'cat' in pets:
    pets.remove('cat')
    
print(pets)

# Filling a Dictionary with User Input
responses = {}

polling_active = True

while polling_active:
    name = input("\nWhat is your name? ")
    response = input("Which mountain would you like to climb someday?")
    
    # Store responses in dictionary
    responses[name] = response
    
    repeat = input("Would you like to add another person? (yes/no)")
    if repeat == 'no':
        polling_active = False
        
print("\n--- Poll Results ---")
for name, response in responses.items():
    print(name + " would like to climb " + response + ".")
