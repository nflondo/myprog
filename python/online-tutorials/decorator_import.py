# https://realpython.com/primer-on-python-decorators/#syntactic-sugar
from decorators import do_twice

@do_twice
def say_whee():
	print("Wheee !")

say_whee()

# decorating a function that accepts arguments
@do_twice
def greet(name):
	print(f"Hello {name}")
	
greet("World")

@do_twice
def return_greeting(name):
	print("Creating greeting")
	return f"Hi {name}"
	
hi_adam = return_greeting("Adam")
print(hi_adam)
