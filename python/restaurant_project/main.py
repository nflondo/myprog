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
    '''
    item1 = Inventory(items = {'salt':2, 'eggs':5})
    print "Before adding:"
    item1.print_inventory()	
    item1.add(item = "eggs")
    print "After adding:"
    item1.print_inventory()	
	
    item1.check(item="salt")
    item1.check(item="onions")
    item1.remove(item="eggs")
    item1.print_inventory()	
    '''
    f = open('inventory.txt')
    lines = f.readlines()
    items = {}
    for l in lines:
        l = l.strip('\n')
        l = l.split('\t')
        i = Ingredient(title = l[0])
        items[i]= int(l[1])
    inventory = Inventory(items)
    inventory.print_inventory()
    f.close()
    #Let user add items to inventory
    f = open('inventory.txt','a')
    
    inv_name = raw_input("New inventory item: ")
    inv_qty = raw_input("New amount: ")
    
    f.write(inv_name,inv_qty)
    f.close
    #inventory.print_inventory()

        #help(i)
        #help(oatmeal)
        #help(item1)

if __name__ == "__main__": 
	main()
