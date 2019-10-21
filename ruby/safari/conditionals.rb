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
