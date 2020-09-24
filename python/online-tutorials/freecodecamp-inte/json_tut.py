#!/usr/bin/env python3
# JSON = JavaScript Object Notation.  Used for data exchange heavily used in web apps
# .json file has a dictionary like syntax/format
# https://www.python-engineer.com/ written and video tutorials
# https://www.python-engineer.com/courses/advancedpython/11-json/

import json
# convert python dict into json format
person = {"name":"john", "age": 30, "city":"New York", "hasChildren": False,
    "titles": ["engineer", "programmer"]}

personJSON = json.dumps(person, indent=4)#json.dumps as a string
#personJSON = json.dumps(person, indent=4, separators=('; ', '= '))
#personJSON = json.dumps(person, indent=4, sort_keys=True)
#print(personJSON)

# dump dictionary into a file
with open('person.json', 'w') as file:
    #json.dump(person, file ) #no s, so for a file
    json.dump(person, file, indent=4)

## json data back into an object (deserialization or decoding)
person = json.loads(personJSON)
print(person)

## json file back into a python object
with open('person.json', 'r') as file:
    person = json.load(file)

print(person)
