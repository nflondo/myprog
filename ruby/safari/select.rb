# Given array of integers, only grab even numbers
# Most languages would use a modulus, not ruby
(1..10).to_a.select{ |x| x.even? }   # to_a converts to array
(1..10).to_a.select(&:even?) # & is a shortcut, allows to skip other part of syntax.  Most common one
(1..10).to_a.select do |x|  # same thing as above
	p x.even?
end

