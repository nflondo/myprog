#!/usr/bin/python
# Inventory class

class Inventory( object):
	'''Inventory class stores objects in a dictionary
       	To instantiate an Inventory object, pass a dictionary
       	with item as key and a number of items
    	''' 
	def __init__( self, items): 
		self.items = items 

	def add( self, item): 
		if self.items.has_key( item): 
			self.items[ item] += 1 
		else: 
			self.items[ item] = 1 

	def remove( self, item): 
		if self.items.has_key( item): 
			if self.items[ item] < 1: 
				print "Can't go negative. Sorry" 
			else: 
				self.items[ item] -= 1 

	def check( self, item): 
		if self.items.has_key(item): 
	            print "Item: {0} is on inventory".format(item)
		    return True 
		else: 
        	    print "Item: {0} is NOT on inventory".format(item)
		    return False 

	def print_inventory(self): 
		for item in self.items: 
		    print item, "-", self.items[item]
