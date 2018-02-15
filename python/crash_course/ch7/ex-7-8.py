# ex 7-8

sandwich_orders = ['blt', 'pastrami', 'blt', 'roast beef', 'pastrami', 'ham', 'turkey', 'pastrami', ]
finished_sandwiches = []

print("\n Sorry, we're out of blt")
while 'blt' in sandwich_orders:
    sandwich_orders.remove('blt')

while sandwich_orders:
    sandwich = sandwich_orders.pop()
    print("\nYour " + sandwich + " is done")
    
    finished_sandwiches.append(sandwich);

print("\n--- The following sandwiches were made ---")    
for sandwich in finished_sandwiches:
    print(sandwich)    
    
places = {}

polling_active = True

while polling_active:
    name = input("\nWhat is your name? ")
    response = input("Dream vacation? ")
    
    # Store responses in dictionary
    places[name] = response
    
    repeat = input("Would you like to add another person? (yes/no)")
    if repeat == 'no':
        polling_active = False
        
print("\n--- Poll Results ---")
for name, response in places.items():
    print(name + " would like to visit " + response + ".")
