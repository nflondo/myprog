print "I will now count my chickens:"

print "Hens", 25 + 30 / 6

# multiplication of 25 * 3 gets done first, then modulus, then substraction
print "Roosters", 100 - 25 * 3.0 % 4.0

print "Now I will  count the eggs:"

# addition and substraction have same priority, so left to right after
# div and mod are done.  Without floating, the fractional part is dropped after decimal
print 3 + 2 + 1 - 5 + 4 % 2 - 1.0 / 4.0 + 6

print "Is it true that 3 + 2 < 5 - 7?"

# Addition gets done before comparisons
print 3 + 2 < 5 - 7

# Will print the result of the addition
print "What is 3 + 2?", 3 + 2

print "What is 5 - 7?", 5 - 7

print "Oh, what's why it's False."

print "How about some more."

# will print boolean result
print "Is it greater?", 5 > -2
print "Is it greater or equal?", 5 >= -2
print "Is it less or equal?", 5 <= -2

