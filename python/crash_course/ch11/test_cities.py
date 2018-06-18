#11-1
import unittest
from city_functions import get_city_country

class CitiesTestCase(unittest.TestCase):
	"""Tests for 'city_functions.py'."""
	
	def test_city_country(self):
		"""Do names like Paris, France work?"""
		city_country = get_city_country('Mexico City', 'Mexico')
		self.assertEqual(city_country, 'Mexico City, Mexico')
	def test_city_country_population(self):
		"""Do names like Santiago, Chile, population 500000 work?"""
		city_country = get_city_country('Mexico City', 'Mexico', '500000')
		self.assertEqual(city_country, 'Mexico City, Mexico - population:500000')

unittest.main()
