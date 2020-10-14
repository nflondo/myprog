#!/usr/bin/env python3
# convert Python objects into JSON objects and save them into a file with the 
# json.dump() method.
#  (Serialization, Encode)

import json

person = {"name": "John", "age": 30, "city": "New York", "hasChildren": False, "titles": ["engineer", "programmer"]}

with open('py_to_json_person.json', 'w') as f:
    json.dump(person, f) # you can also specify indent etc...
