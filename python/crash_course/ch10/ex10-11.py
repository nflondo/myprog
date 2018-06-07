#10-11
import json

filestore = 'fav_number.json'

with open(filestore, 'w') as f_obj:
	user_fav_number = input("What is your favorite number? ")
	json.dump(user_fav_number, f_obj)	
