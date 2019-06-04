# decorator example
def identity(f):
	return f
	
@identity
def foo():
	return 'bar'
