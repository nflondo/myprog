from sys import argv

script, filename = argv

myfile = open(filename)

print "Here's your file %r:" % filename
# This will print the file object to the screen
print myfile.read()

myfile.close()


