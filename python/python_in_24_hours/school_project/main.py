#!/usr/bin/python
# Main

import json
from classes.classroom import *

def main():

    student1 = Student(name="Lili", grade="1")
    student2 = Student(name="Alfredo", grade="1")

    first_grade = Classroom(students=[student1, student2],room_number="1532")
    
    print vars(student1)
    print first_grade.get_JSON_dict()
    #tempdict = [first_grade.get_JSON_dict()]
    #print json.dumps(first_grade.get_JSON_dict(),indent=2)

if __name__ == "__main__": 
	main()


