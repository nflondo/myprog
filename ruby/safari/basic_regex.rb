#Basic regular expressions
mystring = "The quick 12 brown foxes jumped over the 10 lazy dogs"

#p mystring =~ /o/ #returns index of o
p mystring =~ /quick/ #returns index of q

p mystring =~ /z/ ? "Valid" : "Invalid" # case sensitive

p mystring =~ /Z/i ? "Valid" : "Invalid" #i makes it case insensitive

#d: searches for integers +: multiple instances
# to_enum - casts it to enumerator
# map method, Regexp is a ruby class, last_match is one of the methods
# it finds the numbers 12 and 10
p mystring.to_enum(:scan, /\d+/).map { Regexp.last_match }
