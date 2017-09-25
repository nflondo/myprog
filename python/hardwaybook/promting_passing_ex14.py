#!/usr/bin/python
#   
#from sys import argv
import sys

Usage="""Usage: %s <user name> <weight>
   -h              Help.
""" % (sys.argv[0])

if len(sys.argv) == 1:
    print Usage
    sys.exit(1)
    
script, user_name, weight = sys.argv
prompt = '$ '

Usage="""Usage: %s <user name> <weight>
   -h              Help.
""" % (sys.argv[0])

if len(sys.argv) == 1:
    Usage
    sys.exit(1)

print "This is the name of the script: ", sys.argv[0]
print "Number of arguments: ", len(sys.argv)
print "The arguments are: " , str(sys.argv)

print "Hi %s, I'm the %s script." % (user_name, script)
print "I'd like to ask you a few questions."
print "Do you like me %s?" % user_name
likes = raw_input(prompt)

print "Where do you live %s?" % user_name
lives = raw_input(prompt)

print "What kind of computer do you have?"
computer = raw_input(prompt)

print """
Alright, so you said %r about liking me.
You live in %r.  Not sure where that is.
And you have a %r computer.  Nice.
You weight %r lb.  Good.
""" % (likes, lives, computer, weight)
