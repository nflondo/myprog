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

def find_ingredient(cursor, item):
    sql = '''select title,amount from ingredients where title="{item}"'''
    sql = sql.format(item=item)
    results = cursor.execute(sql)
    items = cursor.fetchall()
    if len(items) == 0:
        print "Sorry, that ingredient wasn't found"
    else:
        for item in items:
            print item[0], "-", item[1]

def print_inventory(cursor):
    sql = '''select title,amount from ingredients'''
    results = cursor.execute(sql)
    all_results = results.fetchall()
    for item in all_results:
        print item[0], '-', item[1]

def menu():
    print
    print "What do you want to do?"
    print "A - Add an ingredient"
    print "S - Search for ingredient"
    print "L - List all ingredients"
    print "Q - Quit"
    choice = raw_input ("Choice [A/S/L/Q]: ")
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
            

def main():
    conn = open_database('inventory.db')
    cursor = conn.cursor()
    create_table(cursor)
    #add_ingredients(cursor)
    print_inventory(cursor)
    search_item(cursor)
    conn.commit()
    conn.close()

if __name__ == "__main__": 
    main()
