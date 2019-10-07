# Basic syntax
def full_name(first_name, last_name)
	first_name + " " + last_name
end
puts full_name("Nefi", "Munoz")

# Parenthesis are optional
def full_name first_name, last_name
	first_name + " " + last_name
end
puts full_name "Nefi", "Munoz"

# Newest syntax.  Named arguments
def print_address city:, state:, zip:
	puts city
	puts state
	puts zip
end
# Order does not matter when you have named arguments
print_address city: "Payson", state: "UT", zip: 84651

def sms_generator api_key, num, msg, locale
	# anything
end
sms_generator '987987hhs', 34232323, 'hey there', 'US'

def stream_movie title:, lang: "ENG" # Default argument value
	puts title
	puts lang
end
stream_movie title:"the fountainhead"
# Overwriting the default argument
stream_movie title: "the fountainhead", lang: "SP"
