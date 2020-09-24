#!/usr/bin/env python3
import json
from json import JSONEncoder

class User:

    # Instance variables
    def __init__(self, name, age):
        self.name = name
        self.age = age

user = User('Max', 27)

# custom encoding function
def encode_user(o):
    if isinstance(o, User):
        return {'name': o.name, 'age': o.age, o.__class__.__name__: True}
    else:
        raise TypeError('my: Object of type User is not JSON serializable')

# custom encoding class
class UserEncoder(JSONEncoder):

    def default(self, o):
        if isinstance(o, User):
            return {'name': o.name, 'age': o.age, o.__class__.__name__: True}
        return JSONEncoder.default(self,o)    

userJSON = json.dumps(user, default=encode_user)
print(userJSON)

userJSON = json.dumps(user, cls=UserEncoder)
print(userJSON)

userJSON = UserEncoder().encode(user)
print(userJSON)

# Decode custom objects back
user = json.loads(userJSON)
print(type(user))

def decode_user(dct):
    if User.__name__ in dct:
        return User(name=dct['name'], age=dct['age'])
    else:
        return dct

user = json.loads(userJSON, object_hook=decode_user)
print(user.name)
print(type(user))