#10-11b
import json

filestore = 'fav_number.json'
with open(filestore) as f_obj:
	contents = json.load(f_obj)	
	
print('I know your fav number is '+contents)
