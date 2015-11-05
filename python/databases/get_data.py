#!/usr/bin/python
# create db

import sqlite3

def main(): 
    conn = sqlite3.connect('mytest.db')
    cursor = conn.cursor()
  
    sql = '''select * from students'''
    results = cursor.execute(sql)
    all_students = results.fetchall()
    for stu in all_students:
        print stu
     
     
    cursor.close()

if __name__ == "__main__": 
    main()
