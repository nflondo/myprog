#splat argument.  allows to pass arguments and be treated like an array
def roster *players
	p players
	puts players
end
roster 'Altuve', 'Gattis', 'Springer'

# Takes a hash value (dictionary?) and lets you iterate through those
def roster **players_with_positions
	players_with_positions.each do |player, position|
		puts "Player: #{player}"
		puts "Position: #{position}"
		puts "\n"
	end
end

data = {
	"Altuve": "2nd base",
	"Alex Bregman": "3rd base",
	"Evan Gattis": "Catcher",
	"George Springer": "OF"
	}
roster data

# Optional Arguments
def invoice options={}
	puts options[:company]
	puts options[:total]
	puts options[:something_else]
end

invoice company: "Google", total: 100.0, something_else: "blabla" # doesn't enforce option name
