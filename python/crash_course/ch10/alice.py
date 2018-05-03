
def count_words(filename):
	"""Count the approximate number of words in a file."""
	#enconding needed when system default doesn't match file being read
	try:
		with open(filename, encoding='utf-8') as f_obj: 
			contents = f_obj.read()
	except FileNotFoundError:
		msg = "Sorry, the file " + filename + " does not exist."
		print(msg)
		# We could fail silently using the "pass" keyword instead of 
		# the two lines above this comment
	else:
		#Count the approximate number of words in the file.
		words = contents.split()
		num_words = len(words)
		print("The file " + filename + " has about " + str(num_words) + 
			" words.")

filenames = ['alice.txt', 'siddhartha.txt', 'moby_dick.txt', 
	'little_women.txt']
for filename in filenames:
	count_words(filename)

