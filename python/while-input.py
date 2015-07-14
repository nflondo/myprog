#!/usr/bin/python
# Check user input

age = raw_input("Give me your age in years (e.g. 34): ")
while not age.isdigit():
    print "I'm sorry but {} isn't valid.".format(age)
    age = raw_input("Give me your age in years (e.g. 34): ")
print "Thanks.  Your age is set to {}".format(age)
