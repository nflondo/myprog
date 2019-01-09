# test for get_country_code
import unittest
# Import the function to test
from country_codes import get_country_code

# Include "test" in class name and refer to function being tested
# Inherit unittest.TestCase
class GetCountryCodeTestCase(unittest.TestCase):
	"""Tests for 'country_codes.py'."""
	
	# The methods must start with word "test"
	def test_country_code(self):
		"""Does a country like Mexico or United States get a code assigned?"""
		country_name = 'United States'
#		population = int(float(pop_dict['Value']))
		code = get_country_code(country_name)		
		#Assert methods verifies result received matches expected one
		self.assertEqual(code, 'usa')
		
unittest.main()
