#!/usr/bin/python
year=raw_input("What year were you born [e.g 1980]?")
year=year.strip()

if len(year) != 4 or not year.isdigit():
    print "I'm sorry, need four digits"
else:
    
    print "That's good"
