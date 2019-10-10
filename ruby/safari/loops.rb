## While loops
#i = 0

#while i < 10
	#puts "hey there"  # Will print 10 times because it started at 0
	#i += 1 # There is no i++ or i-- in ruby
#end

## Arrays
#arr = [34, 3434, 4, 23, 3]

#arr.each do |i|
	#p i
#end

#arr.each { |i| p i}  # Another way to print the array

## For loops are not common at all
#for i in 0..42  
#	p i
#end

## Nested iterators in Ruby
teams = {
	"Houston Astros" => {
		"first base" => "Chris Carter",
		"second base" => "Jose Altuve",
		"shortstop" => "Carlos Correa"
	},
	"Texas Rangers" => {
		"first base" => "Prince Fielder",
		"second base" => "R. Odor",
		"shortstop" => "Elvis Andrus"
	}
}

teams.each do |team, players|  
 puts team
 players.each do |position, player|
	p "#{player} starts at #{position}"
 end
end
		
