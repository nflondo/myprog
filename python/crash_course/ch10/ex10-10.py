#ex10-10

def word_count(filename,word_to_find):
	try:
		with open(filename, encoding='utf-8') as f_obj:
			contents = f_obj.read()
	except FileNotFoundError:
		msg = "Sorry, the file " + filename + " does not exists."
		print(msg)
	else:
		#Count how many times word 'the' appears in the file
#		keyword = 'the'
		words_lower = contents.lower()
		words = words_lower.split()
		num_keyword = words.count(word_to_find)	
		print('The word \"' + word_to_find + '\" appears in ' + 
			filename + ' ' + str(num_keyword) + ' times.')

file_list = ['romeo_juliete.txt', 'donquixote.txt', 'metamorphosis.txt']
word = 'house'
for myfile in file_list:
	word_count(myfile,word)
