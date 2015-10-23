#!/usr/bin/python
# Classroom and student classes

class Classroom(object):
    def __init__(self, room_number="", students=[]):
        self.room_number = room_number
        self.students = students

class Student(object):
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade


