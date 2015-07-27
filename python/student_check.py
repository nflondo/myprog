#!/usr/bin/python
# Check if a name is in a class

while True:
    name = raw_input("Give me the name of a student: Enter 'q' to quit: ")
    if name == 'q':
        print "Good Bye"
        break
    while not age.isdigit():
        print "I'm sorry but {0} isn't valid.".format(age)
        age = raw_input("Give me your age in years (e.g. 34): ")
    print "Thanks.  Your age is set to {0}".format(age)
