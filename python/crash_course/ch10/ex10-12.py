#10-12
import json

filestore = 'fav_number2.json'
try:
	with open(filestore) as f_obj:
		contents = json.load(f_obj)	
	print('I know your fav number is '+contents)
except FileNotFoundError:
	with open(filestore, 'w') as f_obj:
		user_fav_number = input("What is your favorite number? ")
		json.dump(user_fav_number, f_obj)
