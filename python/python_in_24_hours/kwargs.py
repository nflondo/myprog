#!/usr/bin/python
# function receives any number of arguments

def test_args(item_one, item_two, **kwargs):
    print item_one
    print item_two
    print kwargs
    
test_args(item_one="Hello", item_two="world.", item_three=" How are you?")
