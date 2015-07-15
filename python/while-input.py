#!/usr/bin/python
# Check user input

while True:
    age = raw_input("Give me your age in years (e.g. 34): Enter 'q' to quit: ")
    if age == 'q':
        print "Good Bye"
        break
    while not age.isdigit():
        print "I'm sorry but {0} isn't valid.".format(age)
        age = raw_input("Give me your age in years (e.g. 34): ")
    print "Thanks.  Your age is set to {0}".format(age)
