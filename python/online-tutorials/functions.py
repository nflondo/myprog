# functions
# https://realpython.com/primer-on-python-decorators/
def say_hello(name):
	return f"Hello {name}"
	
def be_awesome(name):
	return f"Yo {name}, together we're the awesomest!"
	
def greet_bob(greeter_func):
	return greeter_func("Bob")
		
#val=say_hello("Nefi")
#print(val)
#print(greet_bob(say_hello))
#print(greet_bob(be_awesome))

def parent():
	print("Printing from parent() func")
	
	def first_child():
		print("Printing from first_child() func")
		
	def second_child():
		print("Printing from second_child() func")
		
	second_child()
	first_child()
	
#parent()

def return_func(num):
	
	def first_child():
		return "Hi, I am Emma"
		
	def second_child():
		return "Call me Liam"
		
	if num==1:
		return first_child # return without parenthesis, so this is a 
		#pointer to the function, the func still needs to be called.
	else:
		return second_child # return without parenthesis
		
first = return_func(1)
second = return_func(2)
print (first())
print(second())
