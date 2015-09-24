#!/usr/bin/python
# Ingredient class

class Ingredient( object):
    	'''Ingredient class allows to create ingredient objects
       	which contain a title and a description
    	'''
 
	def __init__( self, title, description =''): 
		self.title = title 
		self.description = description
 
	def __str__( self):
		return self.title
