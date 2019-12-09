#https://projecteuler.net/problem=20
def factorial_value_sum_generator(factorial)
	# creates an array and orders it in reverse
	arr = (1..factorial).to_a.reverse.each {|i| factorial += factorial * (i - 1)}
	# to_s.split(//) will grab each individual char in the string
	# .map(&:to_i) will convert each element into a digit
	# .inject will return a sum of all the numbers in the array
	factorial.to_s.split(//).map(&:to_i).inject(:+)
end

p factorial_value_sum_generator(100)
