#11-3
import unittest
from employee import Employee 

class TestEmployeeSalary(unittest.TestCase):
	"""Tests for the class employee.py"""
	
	def setUp(self):
		"""Create instance of class"""
		self.my_employee = Employee('Joel', 'Kitchen', 10000)
		
	def test_give_default_raise(self):
		"""Tests employee gets default raise"""
		self.my_employee.give_raise()
		self.assertEqual(15000, self.my_employee.annual_salary)
		
	def test_give_custom_raise(self,raise_amount=10000):
		"""Tests employee gets custom raise"""	
		self.my_employee.give_raise(raise_amount)
		self.assertEqual(20000, self.my_employee.annual_salary)
		
unittest.main()


