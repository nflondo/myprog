# need to import sys "module"
from sys import argv

# unpacks argv into a variable for each value
script, first , second, third, fourth, fifth = argv

print "The script is called:", script
print "Your first variable is:", first
print "Your second variable is:", second
print "Your third variable is:", third
print "Your fourth variable is:", fourth
print "Your fifth variable is:", fifth
