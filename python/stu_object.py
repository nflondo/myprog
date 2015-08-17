#!/usr/bin/python
# Demos how to work with objects

class Student(object):
 
    def __init__(self, name="", school="", grade=""): 
        if not name: 
            name = raw_input(" What is the student's name? ") 
        if not school: 
            school = raw_input(" What is the student's school? ") 
        if not grade: 
            grade = self.get_grade() 
        self.name = name 
        self.school = school 
        self.grade = grade 
        self.print_student() 

    def get_grade(self): 
        while True: 
            grade = raw_input(" What is the student's grade? [K, 1-5] ") 
            if grade.lower() not in [' k', '1', '2', '3', '4', '5']: 
                print "I'm sorry, but {0} isn't valid.".format(grade) 
            else: 
                return grade 

    def print_student(self): 
        print "Name: {0}".format(self.name) 
        print "School: {0}".format(self.school) 
        print "Grade: {0}".format(self.grade) 


def main(): 
    student1 = Student() 
    student2 = Student(name ="Byron Bale", grade ="2", school ="Minnieville") 

if __name__ == "__main__": 
    main()

