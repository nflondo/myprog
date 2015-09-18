#!/usr/bin/python
# Ingredient class

class Ingredient( object):
 
	def __init__( self, title, description =''): 
		self.title = title 
		self.description = description
 
	def __str__( self):
		return self.title
