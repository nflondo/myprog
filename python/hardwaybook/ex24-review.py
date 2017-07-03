print "Let's practice everything"
print 'You\'d need to  know \'bout escapes with \\ that do \n newlines and \t tabs.'

poem="""
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion  from intuition
and requires an explanation
\n\t\twhere there is none.
"""

print "----------------"
# This prints a string variable
print poem
print "----------------"

five = 10 - 2 + 3 - 6
print "This should be five: %s" %five

def secret_formula(started):
    jelly_beans = started * 500
    jars = jelly_beans / 1000
    crates = jars / 100
    # returns three values, so need 3 vars to cath them all
    return jelly_beans, jars, crates
    
start_point = 10000
# These 3 vars, catch all values returned by function 'secret_formula'
beans, jars, crates = secret_formula(start_point)

print "With a starting poing of: %d" % start_point
print "We'd have %d beans, %d jars, and %d cratess." % (beans, jars, crates)

start_point = start_point / 10

print "We can also do that this way:"
# Short version.  Print all 3 return values
print "We'd have %d beans, %d jars, and %d crates." % secret_formula(start_point)
