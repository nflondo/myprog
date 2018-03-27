# 9-14

from random import randint

class Die():
    """ Represents a die.  Default size is 6"""
    
    def __init__(self, sides=6):
        self.sides = sides
        
    def roll_die(self):
        num = randint(1,self.sides)
        print(num)

die1 = Die()
for roll in range(1,die1.sides):
    die1.roll_die()

print("=" * 15)

die10 = Die(10)
for roll in range(1,die10.sides):
    die10.roll_die()

print("=" * 15)

die20 = Die(20)
for roll in range(1,die20.sides):
    die20.roll_die()
