# simple decorator
# https://realpython.com/primer-on-python-decorators/
from datetime import datetime

def my_decorator(func):
	def wrapper():
		print("Before call func")
		func()
		print("After call func")
	
	return wrapper
	
def say_whee():
	print("Whee!")
	
say_whee = my_decorator(say_whee)

print (say_whee())

# again but with a conditional for func
def not_at_night(func):
	def wrapper():
		if 7 <= datetime.now().hour < 22:
			func()
		else:
			pass # Hush, people sleeping
	
	return wrapper
	
say_whee=not_at_night(say_whee)
print(say_whee())
	
