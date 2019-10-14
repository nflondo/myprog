y = Array.new
y[0] = 543
#puts y
### items 1-9 are printed as nil
y[10] = 432
#puts y

## Iterate over array skipping the nil ones
y.each do |i|
	puts i
end

# Removing elements from array
x = ["asfs", 3, 4, 12, "asf", "b", true, 34, 2, 4, 4, 4]
puts x.length
x.delete("asf")  # deletes specific element
puts x.length
# deletes element index
x.delete_at(2)
puts x.length

batting_averages = [0.300, 0.180, 0.220, 0.250]
puts "initial: #{batting_averages}"

batting_averages.delete_if {|average| average < 0.24}
puts "after delete: #{batting_averages}"
