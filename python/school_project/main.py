#!/usr/bin/python
# Main

import json
from classes.classroom import *

def main():

    student1 = Student(name="Lili", grade="1")
    student2 = Student(name="Alfredo", grade="1")

    first_grade = Classroom(students=[student1, student2],room_number="5560")


if __name__ == "__main__": 
	main()


