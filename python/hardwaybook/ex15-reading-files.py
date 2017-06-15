from sys import argv

script, filename = argv

# opens a file and returns a file object
txt = open(filename)

print "Here's your file %r:" % filename
# This will print the file object to the screen
print txt.read()
#print txt.readlines()
txt.close()

print "Type the filename again:"
file_again = raw_input("> ")

#open a given file name
txt_again = open(file_again)
print txt_again.read()
txt_again.close()

# dump it to screen
#print txt_again.read()
