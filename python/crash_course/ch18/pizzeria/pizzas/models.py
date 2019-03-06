from django.db import models

# Create your models here.
class Pizza(models.Model):
	"""A Pizza"""	
	name = models.CharField(max_length=100)
	date_added = models.DateTimeField(auto_now_add=True)
	
	def __str__(self):
		"""Return a string representation of the model."""
		return self.name

class Topping(models.Model):
	"""Specific toppings for pizza slice"""
	pizza = models.ForeignKey(Pizza, on_delete=models.CASCADE)	
	name = models.TextField()
	
	def __str__(self):
		"""Return a string representation of the model."""
		if len(self.name) > 50:
			return self.name[:50] + "..."
		else:
			return self.name 
