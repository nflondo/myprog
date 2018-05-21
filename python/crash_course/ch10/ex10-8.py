def print_file(filename):
	"""Print contents of file to the screen"""
	#enconding needed when system default doesn't match file being read
	try:
		with open(filename, encoding='utf-8') as f_obj: 
			contents = f_obj.read()
	except FileNotFoundError:
		msg = "Sorry, the file " + filename + " does not exist."
		print(msg)
	else:
		# print file to screen
		
