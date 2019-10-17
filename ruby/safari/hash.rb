## one way to create a hash
positions = { first_base: "Chris Carter", second_base: "Jose Altuve", short_stop: "Carlos Correa" }
## another syntax, use hash rocket
positions = { "first_base" => "Chris Carter", "second_base" => "Jose Altuve", "short_stop" => "Carlos Correa" }
## third way is to use the : in front of the keys
positions = { :first_base => "Chris Carter", :second_base => "Jose Altuve", :short_stop => "Carlos Correa" }

#puts positions
## Get second key
puts positions[:second_base]
p "hash positions: #{positions}"
## Delete from a hash
positions.delete(:second_base)
p "hash positions again: #{positions}"

## How to iterate over a hash.  Only over keys or values
positions.each_key do |key|
	puts "key: #{key}"
end

## Over values
positions.each_value do |value|
	puts "value: #{value}"
end
