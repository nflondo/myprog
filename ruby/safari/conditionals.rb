## Conditionals in Ruby
x = 10
y = 100
z = 10
## if
if x == y
	puts "x is the same as y"
else
	puts "x and y are different"
end

## Unless
players = ["Correa", "Carter", "Altuve"]
unless players.empty?  # Print if not empty
	players.each {|player| puts player}
end
# another way of doing it
players.each {|player| puts player} unless players.empty?
# or
players.each {|player| puts player} if !players.empty?

## if else
if x == y
	puts "x is equal to y"
elsif x >= z
	puts "x is greater than or equal to z"
else
	puts "something else"
end

## Compound conditionals
if x == y && x == z
	puts "equals to everything"	
else
	puts "only one is equal"
end
if x == y || x == z
	puts "in the if or, so one is equals"	
else
	puts "none are equal"
end
# both sides have to be true.  Parenthesis gets executed first.
if (x == 10 && x == z) && x == y
	puts "from the double &&"
end

# only one side has to be true
if (x == 10 && x == z) || x == y
	puts "from the double ||"
end
