total = 0
[3,2,4,53,434534,4,4,].each do |i|
total += i
end
puts total

# below is equivalent to above code, but using inject
# Possible cause + below is a method in Ruby
# Great way to grab a sum
puts [3,2,4,53,434534,4,4,].inject(&:+)
# same but with multiplication
puts [3,2,4,53,434534,4,4,].inject(&:*)
