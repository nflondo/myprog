#!/usr/bin/python
# Classroom and student classes

class Classroom(object):
    def __init__(self, room_number="", students=[]):
        self.room_number = room_number
        self.students = students

    def get_JSON_dict(self):
        d = vars(self)
        student_list = []
        for s in self.students:
            student_list.append(vars(s))
        d['students'] = student_list
        return d

class Student(object):
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade


