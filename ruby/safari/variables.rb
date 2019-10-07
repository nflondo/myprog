#Local variables (common)
10.times do
	x = 10
#	p x
end

# Global Variables
10.times do
	$x = 10  # global variables prefixed with $
end
p "Global var:"
p $x

# Instance Variables (more common)
@batting_average = 300

# Constants
# Ruby allows to change values of constants
TEAM = "Angels"
TEAM = "Athletics"
p TEAM

# Class Variables (not very common at all)
class MyClass
	@@teams = ["A's", "Tigers"]
end
