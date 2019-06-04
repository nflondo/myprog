#!/usr/bin/python
# Main
# Recipe and Inventory program.  The inventory part reads inventory from a file 'inventory.txt' and sticks that information into
# a dictionary where more items can be added or remove.  Still have to add a way to save the modified inventory back into a file.

from classes.ingredient import Ingredient 
from classes.recipe import Recipe 
from classes.inventory import Inventory

def main(): 
    #Recipe instantiation and printing
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
    #Inventory part.  Open file and put it in a dictionary
    f = open('/home/myprog/python/restaurant_project/inventory.txt')
    lines = f.readlines()
    items = {}
    for l in lines:
        l = l.strip('\n')
        l = l.split('\t')
        items[l[0]]=int(l[1])        
#These were the original lines from book(didn't work)
#i = Ingredient(title=l[0])
#       items[i]= int(l[1])
    
    #For debugging could print the items in the dictionary    
    #for a in items:
    #    print a,items[a]
     
    inventory = Inventory(items)
  
    # User Menu
    while True:
        choice=raw_input( "\t1- Add items\n\t2- Remove Items\n\t3- Print Inventory\n\tq - Quit\n\t Please choose: ")
        if choice.lower() in ['q','quit']:
            print "Good Bye"
            break
        #int(choice)
        if choice == '1':    
            inv_add = raw_input("New inventory item: ")
    #inv_add = inv_add.strip('\n')
    #inv_qty = raw_input("New amount: ")
            inventory.check(item=inv_add)
   
            inventory.add(item=inv_add)    
            
        elif choice == '2':
            inv_remove = raw_input("Inventory remove: ")
            exists=inventory.check(item=inv_remove)
            print "exists:", exists
            if exists:
                inventory.remove(item=inv_remove)
                print "DEBUG: Ran inventory.remove"
                   
        elif choice == '3':
            inventory.print_inventory() 

'''
    f = open('inventory.txt','r+w')
    for a in items:
        f.write(a,items[a])
    f.close
        #help(i)
        #help(oatmeal)
        #help(item1)
'''
if __name__ == "__main__": 
	main()
