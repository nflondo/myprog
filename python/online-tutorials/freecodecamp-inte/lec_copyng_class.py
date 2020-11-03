#!/usr/bin/env python3
import copy
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

class Company:
    def __init__(self, boss, employee):
        self.boss = boss
        self.employee = employee

p1 = Person('Alex', 27)
p4 = Person('Joe', 55)
p2 = p1 #not a real copy

p2.age = 28
print(p2.age)
print(p1.age) # both change to 28, cause is not an actual copy

p3 = copy.copy(p1)
p3.age = 209
print(p1.age)
print(p3.age)

# deep copying
company = Company(p4, p1)
company_clone = copy.deepcopy(company)
company_clone.boss.age = 56
print(company_clone.boss.age)
print(company.boss.age)