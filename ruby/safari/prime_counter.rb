# Finds all prime numbers from 0 to 2 million
require 'prime'

prime_array = Prime.take_while { |p| p < 2_000_000 } # _ for readability only, Ruby ignores them

total_count = prime_array.inject { |sum, x| sum + x } # Add all numbers together (sum =+ sum ?)

p total_count
#142913828922
