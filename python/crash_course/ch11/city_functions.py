#11-1 

def get_city_country(city_name, country_name, population=''):
	"""Generate a City and Country string"""
	if population:
		city_country = city_name + ', ' + country_name 	+ ' - population:' + population
	else:
		city_country = city_name + ', ' + country_name 
	return city_country
	
	
