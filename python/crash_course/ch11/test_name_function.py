import unittest
# Import the function to test
from name_function import get_formatted_name

# Include "test" in class name and refer to function being tested
# Inherit unittest.TestCase
class NamesTestCase(unittest.TestCase):
	"""Tests for 'name_function.py'."""
	
	# The methods must start with word "test"
	def test_first_last_name(self):
		"""Do names like 'Janis Joplin' work?"""
		formatted_name = get_formatted_name('Janis', 'joplin')
		#Assert methods verifies result received matches expected one
		self.assertEqual(formatted_name, 'Janis Joplin')
		
	def test_first_last_middle_name(self):
		"""Do names like 'Wolfgang Amadeus Mozart' work?"""
		formatted_name = get_formatted_name('wolfgang', 'mozart', 'ama')
		self.assertEqual(formatted_name, 'Wolfgang Ama Mozart')
		
unittest.main()
