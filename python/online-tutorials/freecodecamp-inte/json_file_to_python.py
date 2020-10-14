 #!/usr/bin/env python3
 #  load data from a file and convert it to a Python object with the json.load()
 #  method.
import json

with open('py_to_json_person.json', 'r') as f:
    person = json.load(f)
    print(person)