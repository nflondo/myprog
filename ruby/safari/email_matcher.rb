#email matcher
VALID_EMAIL_REGEX = /\A([\w+\-].?)+@[a-z\d\-]+(\.[a-z]+)*\.[a-z]+\z/i

def is_valid_email? email #no need for parenthesis to pass arg
	email =~ VALID_EMAIL_REGEX
end

p is_valid_email?("jordan@hudgens.com") ? "Valid" : "Invalid"
p is_valid_email?("jordanhudgens.com") ? "Valid" : "Invalid"
p is_valid_email?("jordan.h@hudgens.com") ? "Valid" : "Invalid"
p is_valid_email?("jordan@hudgens") ? "Valid" : "Invalid"
p is_valid_email?("jordan_h@hudgens.net") ? "Valid" : "Invalid"
