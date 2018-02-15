# multiples of 10

number = input("Give me a number: ")
number = int(number)

if number % 10 == 0:
    print("\nNumber " + str(number) + " is a multiple of 10")
else:
    print("\nNumber " + str(number) + " is NOT a multiple of 10")
