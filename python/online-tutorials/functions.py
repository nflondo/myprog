# functions
# https://realpython.com/primer-on-python-decorators/
def say_hello(name):
	return f"Hello {name}"
	
def be_awesome(name):
	return f"Yo {name}, together we're the awesomest!"
	
def greet_bob(greeter_func):
	return greeter_func("Bob")
		
val=say_hello("Nefi")
print(val)

print(greet_bob(say_hello))

print(greet_bob(be_awesome))
