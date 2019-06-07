# first decorator

def my_decorator(func):
	def wrapper():
		print("my_decorator: Before call func")
		func()
		print("my_decorator: After call func")
	
	return wrapper
	
@my_decorator
def say_whee():
	print("Wheeeee!")

print(say_whee())

# So, @my_decorator is just an easier way of saying 
# say_whee = my_decorator(say_whee). 
