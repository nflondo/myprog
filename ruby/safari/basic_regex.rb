#Basic regular expressions
mystring = "The quick 12 brown foxes jumped over the 10 lazy dogs"

#p mystring =~ /o/ #returns index of o
p mystring =~ /quick/ #returns index of q

p mystring =~ /z/ ? "Valid" : "Invalid" # case sensitive

p mystring =~ /Z/i ? "Valid" : "Invalid" #i makes it case insensitive

#d: searches for integers +: multiple instances
p mystring.to_enum(:scan, /\d+/).map { Regexp.last_match }
