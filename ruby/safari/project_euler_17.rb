# Problem 17 from projec euler (https://projecteuler.net/problem=17)
# Count the number of letters in all the words
# Requires humanize gem (gem install humanize)
require 'humanize'

no_space_array, total = [], 0
# to_a  converts it into an array
# humanize spells out the elements
# word.delete deletes spaces and - from each element and puts it into no_space_array
(1..1000).to_a.map(&:humanize).each {|word| no_space_array << word.delete(" ").delete("-")}.each { |element| total += element.length }

p total
