#!/usr/bin/python
# Main

from classes.ingredient import Ingredient 
from classes.recipe import Recipe 
from classes.inventory import Inventory

def main(): 
	i = Ingredient( title =" egg") 

	r = Recipe( title ="Scrambled eggs", ingredients =[ i], directions =['Break egg', 'Beat egg', 'Cook egg']) 

	r.print_recipe()
	
	oats = Ingredient(title = "Oats")
	oatmeal = Recipe(title = "Oatmeal", ingredients = [oats], directions =['cook oatmeal in a pan', 'serve oatmeal'])
	oatmeal.print_recipe()
	
	item1 = Inventory(items = "salt")
	item1.check()
	 
if __name__ == "__main__": 
	main()
