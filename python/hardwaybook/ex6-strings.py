x = "There are %d types of people." % 10
binary = "binary"
do_not = "don't"
y = "Those who know %s and those who %s." %(binary, do_not)

# This prints the strings
print x
print y

# This prints the strings with single quotes. Literal
print "I said: %r." % x
#
print "I also said: %s." % y

hilarious = False
joke_evaluation = "Isn't that joke so funny?! %r"

# prints variable (which is a string) followed by another string
print joke_evaluation % hilarious

w = "This is the left side of..."
e = "a string with a right side."

# This does string concatenation
print w + e
