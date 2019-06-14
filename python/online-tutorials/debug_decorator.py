# print the arguments a function is called with as well as its return value
# every time the function is called
import functools

def debug(func):
	"""Print the function signature and return value"""
	@functools.wraps(func)
	def wrapper_debug(*args, **kwargs):
		#Create a list of the positional arguments.  Use repr() to get a nice string
		# representing each argument.
		args_repr = [repr(a) for a in args] 													
		#Create a list of the keyword arguments.  The f-string formats each argument
		#as key=value where the !r specifier means that repr() is used to represent a value.
		kwargs_repr = [f"{k}={v!r}" for k, v in kwargs.items()]
		#The lists of positional and keyword arguments is joined together to one signature
		#string with each argument separated by comma.
		signature = ", ".join(args_repr + kwargs_repr)			
		print(f"Calling {func.__name__}({signature})")
		value = func(*args, **kwargs)
		#The return value is printed after the function is executed
		print(f"{func.__name__!r} returned {value!r}")
		return value
	return wrapper_debug

@debug
def make_greeting(name, age=None):
	if age is None:
		return f"Howdy {name}!"
	else:
		return f"Whoa {name}! {age} already, you are growing up!"
		
make_greeting("Richard", age=112)
make_greeting("Benjamin")
