# Mixing positional and arbitrary arguments.  Arbitrary must be last
def make_pizza(size, *toppings):
    print("\nMaking a " + str(size) + "-inch pizza with the following" +
            " toppings: ")
    for top in toppings:
        print("- " + top)
