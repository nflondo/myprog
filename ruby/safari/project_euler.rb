# Problem 16 of project euler
# Add all the numbers in the answer of 2^1000
p (2 ** 1000).to_s.split(//).map(&:to_i).inject(:+)   # ** exponent
								#split puts each element into array
								#map, maps each element to integers
								#inject will give us a sum
