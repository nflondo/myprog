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
        i = Ingredient(title=l[0])
        print i
        items[i]= int(l[1])
    for a in items:
        print a,items[a]
    
     
    #inventory = Inventory(items)
    
    #inventory.print_inventory()
    
    #Let user add items to inventory
    inv_remove = raw_input("Inventory remove: ")
    inventory.remove(item=inv_remove)
    inv_add = raw_input("New inventory item: ")
    #inv_add = inv_add.strip('\n')
    #inv_qty = raw_input("New amount: ")
    inventory.check(item=inv_add)
    
    inventory.add(item=inv_add)
    
    #f = open('inventory.txt','r+w')
    #f.write(str(inventory))
    inventory.print_inventory()
    inv_add2 = raw_input("New inventory item: ")
    inventory.add(item=inv_add2)
    inventory.print_inventory()

    inv_remove = raw_input("Inventory item to remove: ")
    inventory.remove(item=inv_remove)
    inventory.print_inventory()
    #f.close
        #help(i)
        #help(oatmeal)
        #help(item1)

if __name__ == "__main__": 
	main()
