teams = ["astros", "yankees", "rangers", "mets", "cardinals"]
puts teams

## Join
one_string = teams.join(',')
puts "one string: #{one_string}"

with_tilde = teams.join('~')
puts "with tilde: #{with_tilde}"

## Pushing and popping
# Pushing add value to end of array, pop will remove it
 
teams.push("marlins")
puts "teams: #{teams}"
teams.push("red sox", "blue jays")
puts "teams: #{teams}"

mypop = teams.pop
puts "teams with pop: #{teams}"
puts "mypop= #{mypop}"
