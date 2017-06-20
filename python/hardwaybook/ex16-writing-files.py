from sys import argv

script, filename = argv

print "We're going to erase %r." % filename
print "If you don't want that, hit CTRL-C (^C)."
print "If you do want that, hit RETURN."
# This just allows RETURN to continue
raw_input("?")

# Open for writing.  It automatically truncates the file when opened for writing,
# so no need to truncate explicitly in theory

print "Opening the file..."
target = open(filename, 'w')

# deletes contents of file
print "Truncating the file.  Goodbye!"
target.truncate()

print "Now I'm going to ask you for three lines."

line1 = raw_input("line 1: ")
line2 = raw_input("line 2: ")
line3 = raw_input("line 3: ")

print "I'm going to write these  to the file."

# writes one line followed by a RETURN
target.write(line1 + "\n" + line2 + "\n" + line3 + "\n")

#target.write(line1)
#target.write("\n")
#target.write(line2)
#target.write("\n")
#target.write(line3)
#target.write("\n")

print "And finally, we close it."
target.close()
