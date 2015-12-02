#!/usr/bin/python
# Inventory program

import sqlite3

def open_database(db_name):
    conn = sqlite3.connect(db_name)
    return conn

def create_table(cursor):
    sql = '''create table ingredients (title text, amount float, description text)'''
    
    try:
        cursor.execute(sql)
    except:
        pass

def add_ingredients(cursor):

    while True:
        ingredient = raw_input("Name of ingredient (q to quit): ")
        if ingredient.lower() != 'q':
            num = raw_input ("Number in storage: ")
            description = raw_input("Description: ")
            sql = '''insert into ingredients(title, amount, description)values(:title, :amount, :description)'''
            cursor.execute(sql, {"title":ingredient, "amount":num, "description":description})
            print "Added !"
        else:
            print "OK, quitting."
            break

def find_ingredient(cursor,ingredient):
    sql = '''select title,amount from ingredients where title="{item}"'''
    sql = sql.format(item=ingredient)
    results = cursor.execute(sql)
    items = cursor.fetchall()
    if len(items) == 0:
        print "Sorry, that ingredient wasn't found"
    else:
        for item in items:
            print item[0], "-", item[1]

def list_ingredients(cursor):
    sql = '''select title,amount from ingredients'''
    results = cursor.execute(sql)
    all_results = cursor.fetchall()
    print "Items in the inventory"
    for item in all_results:
        print item[0], '-', item[1]

def menu():
    print
    print "What do you want to do?"
    print "A - Add an ingredient"
    print "S - Search for ingredient"
    print "L - List all ingredients"
    print "U - Update an ingredient"
    print "D - Delete an ingredient"
    print "Q - Quit"
    choice = raw_input ("Choice [A/S/L/U/D/Q]: ")
    return choice[0].lower()

def search_item(cursor):
    findme = raw_input("Item to search: ")
    sql = '''select title,amount from ingredients where title like :searchme'''
    results = cursor.execute(sql, {"searchme":findme})
    all_results = results.fetchall()
    if all_results:
        for item in all_results:
            print item
    else:
        print "Item:",findme,"not found."
            
def update_ingredient(cursor):
    item = raw_input("Which item? ")
    column = raw_input("What column (title, amount, description)? ")
    value = raw_input("To what value? ")
    if column[0].lower() == 't':
        sql = '''UPDATE ingredients SET title="{value}" WHERE title="{title}"'''
    elif column[0].lower() == 'a':
        sql = '''UPDATE ingredients SET amount="{value}" WHERE title="{title}"'''        
    elif column[0].lower() == 'd':
        sql = '''UPDATE ingredients SET description="{value}" WHERE title="{title}"'''
    else:
        print "Sorry, that's not valid."
        return
    sql = sql.format(value=value, title=item)
    cursor.execute(sql)

def delete_ingredient(cursor):
    item = raw_input("Which item to delete? (title)")
    
    sql = '''select title from ingredients where title="{title}"'''
    sql = sql.format(title=item)
    results = cursor.execute(sql)
    items = cursor.fetchall()
    if len(items) == 0:
        print "Sorry, that ingredient wasn't found"
    else:
    
        sql = '''DELETE from ingredients WHERE title="{title}" '''
        sql = sql.format(title=item)
        print "Item:", item, "deleted."
        cursor.execute(sql)
        
def main():
    conn = open_database('inventory.db')
    cursor = conn.cursor()
    while True:    
        choice = menu()
        if choice == 'a':
            add_ingredients(cursor)
        elif choice == 's':
            item = raw_input("What ingredient? ")
            find_ingredient(cursor=cursor, ingredient=item)
        elif choice == 'l':
            list_ingredients(cursor)
        elif choice == 'u':
            update_ingredient(cursor) 
        elif choice == 'd':
            delete_ingredient(cursor) 
        elif choice == 'q':  
            print "Goodbye"
            break
        else:
            print "Sorry, that's not valid"
    #create_table(cursor)
    #add_ingredients(cursor)
    #print_inventory(cursor)
    #search_item(cursor)
    conn.commit()
    conn.close()

if __name__ == "__main__": 
    main()
