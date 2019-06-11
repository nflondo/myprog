#decorators
# https://realpython.com/primer-on-python-decorators/#syntactic-sugar
import functools

def do_twice(func):
	# *args and **kwargs will accept 0 to any arguments
	# *args = all functions parameters
	# **kwargs = all keyword arguments
	@functools.wraps(func) # Allows wrapped function to preserve its identity
	def wrapper_do_twice(*args, **kwargs):
		func(*args, **kwargs)
		return func(*args, **kwargs)		
	
	return wrapper_do_twice
