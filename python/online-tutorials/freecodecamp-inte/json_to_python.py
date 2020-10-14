 #!/usr/bin/env python3
 # Convert a JSON string into a Python object with the json.loads() method. 
 # The result will be a Python dictionary.
 # (Deserialization, Decode)
import json
person_json = """
{
    "age": 30, 
    "city": "New York",
    "hasChildren": false, 
    "name": "John",
    "titles": [
        "engineer",
        "programmer"
    ]
}
"""
person = json.loads(person_json)
print(person)