## Given array of integers, only grab even numbers
## Most languages would use a modulus, not ruby
#(1..10).to_a.select{ |x| x.even? }   # to_a converts to array
#(1..10).to_a.select(&:even?) # & is a shortcut, allows to skip other part of syntax.  Most common one
#(1..10).to_a.select do |x|  # same thing as above
	#p x.even?
#end

# Given an array of words, and return only words that are over 5 letters
arr = %w(The quick brown fox jumped over the lazy dog)
p (arr.select { |x| x.length > 5 })

# Return all of the vowels
p %w(a b c d e f g).select { |v| v =~ /[aeiou]/ }

p ["1" "23.0", "0", "4"].map { |x| x.to_i }

p ["1" "23.0", "0", "4"].map(&:to_i)

p ("a".."g").to_a.map { |i| i * 2 }

# Prints out two values
p Hash[[1, 2.1, 3.33, 0.9].map { |x| [x,x.to_i] }]

# convert array of strings into a Hash
p Hash[%w(A dynamic open source programming language).map { |x| [x,x.length] }]

# Has values and convert them url safe
{:a => "foo", :b => "bar"}.map{|a, b| "#{a}=#{b}"}.join('&') 
