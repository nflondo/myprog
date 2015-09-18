#!/usr/bin/python
# Main

from classes.ingredient import Ingredient 
from classes.recipe import Recipe 

def main(): 
	i = Ingredient( title =" egg") 

	r = Recipe( title =" Scrambled eggs", ingredients =[ i], directions =[' Break egg', 'Beat egg', 'Cook egg']) 

	r.print_recipe()
	 
if __name__ == "__main__": 
	main()
