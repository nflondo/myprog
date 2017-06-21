from sys import argv
from os.path import exists

script, from_file, to_file = argv

print "Copying from %s to %s" % (from_file, to_file)

#we could do these two on one line too, how?
# long:
#in_file = open(from_file)
#indata = in_file.read()

# shorter:
#in_file = open(from_file); indata = in_file.read()

# shortest:
indata = open(from_file).read()

# len() gets length of the string and returns a number
print "The input file is %d bytes long" % len(indata)

print "Does the output file exists? %r" % exists(to_file)
#print "Ready, hit RETURN to continue, CTRL-C to abort."
#raw_input()

out_file = open(to_file, 'w')
out_file.write(indata)

print "Alright, all done."

out_file.close()
#in_file.close()
