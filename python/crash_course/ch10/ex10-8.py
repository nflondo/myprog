def print_file(filename):
	"""Print contents of file to the screen"""
	#enconding needed when system default doesn't match file being read
	try:
		with open(filename, encoding='utf-8') as f_obj: 
			contents = f_obj.read()
#	except FileNotFoundError:
#		msg = "Sorry, the file " + filename + " does not exist."
#		print(msg)
	except FileNotFoundError:
		pass
	else:
		# print file to screen
		print(contents)
		
filename_list=['cats.txt','dogs.txt']

for filedoc in filename_list:
	print_file(filedoc)


		
