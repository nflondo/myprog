#!/usr/bin/python
# Recipe class

class Recipe( object): 
	def __init__( self, title, ingredients =[], directions =[], note =""): 
		self.title = title 
		self.ingredients = ingredients 
		self.directions = directions 
		self.note = note 

	def __str__( self): 
		return self.title 

	def print_recipe( self): 
		print self.title 
		print "Ingredients:" 
		for ingredient in self.ingredients: 
			print ingredient 
		print "Directions:" 
		n = 1 
		
		for direction in self.directions: 
			print n, "-", direction 
			n += 1 
		if self.note: 
			print "Special note:" 
			print self.note
