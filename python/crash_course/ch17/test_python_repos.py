# test for get_python_repos
import unittest
# Import the program to test
import python_repos

# Include "test" in class name and refer to function being tested
# Inherit unittest.TestCase
class PythonReposTestCase(unittest.TestCase):
	"""Tests for 'python_repos.py'."""
	
	# The methods must start with word "test"
	def test_status_code(self):
		##### incomplete ####  
		"""Does a country like Mexico or United States get a code assigned?"""
		country_name = 'United States'
#		population = int(float(pop_dict['Value']))
		code = get_country_code(country_name)		
		#Assert methods verifies result received matches expected one
		self.assertEqual(code, 'usa')
		
unittest.main()
