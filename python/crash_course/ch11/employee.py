
class Employee():
	"""Manages employees salaries"""
	
	def __init__(self, first_name, last_name, annual_salary):
		"""Store employee info"""
		self.first_name = first_name
		self.last_name = last_name
		self.annual_salary = annual_salary
		
	def give_raise(self, raise_amount=''):
		default_raise_amount = 5000
		if raise_amount:
			self.annual_salary = self.annual_salary + raise_amount
		else:
			self.annual_salary = self.annual_salary + default_raise_amount

"""
my_employee = Employee('Arturo', 'Ramos', 5000)
my_employee.give_raise()
print(my_employee.annual_salary)
my_employee.give_raise(raise_amount=10000)
print(my_employee.annual_salary)
"""
