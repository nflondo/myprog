##hash methods
people = {jordan: 32, tiffany: 27, kristine: 10}
puts people

## Add to a hash
people[:leann] = 42
puts "people after add: \n #{people}"

## Get a hash where API wants reverse values, meaning values are the keys.
people_2 = people.invert
puts "People_2: \n #{people_2}"

## Merging hashes
people_merged = people.merge(people_2)
puts "Merged hash: \n #{people_merged}"

## Convert a hash into an array.  This will make nested arrays, because each
# element inside the array will be an array with two elements, key and value.
people_array = people.to_a
puts "People array: \n #{people_array}"

## Print out keys and values
puts "People Keys: #{people.keys}"

puts "People Values: #{people.values}"
