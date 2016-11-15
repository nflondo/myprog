#!/usr/bin/python

from sys import argv

# This unpacks the argv variable into 4 variables.
# Before argv, had all the arguments.
script, hours = argv

count = int(raw_input("How many seconds in an hour? "))

# Arguments passed to argv are strings, so they have to be converted
hours = int(hours)

result = hours * 60 * count

print "The result is:", result, "secs"
