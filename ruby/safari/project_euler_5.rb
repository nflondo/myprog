#https://projecteuler.net/problem=5
# .reduce(:lcm) - applies the operation to all elements in the array.  Same as
# inject
p (1..20).to_a.reduce(:lcm) #lcm = least common multiple
