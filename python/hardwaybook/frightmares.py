# You go to several rooms.  You have to answer a question in each room.  If you
# answer correctly, you get a candy.  If you don't, you get a penalty.
# Pirate room: What does a pirate say? (arrg) Penalty: You lose an eye
# Day of the dead room: How do you say dead in spanish? (muerto) Penalty: You 
# wait 5 min
# 60's room: Can you dance? (dance) Penalty: you get a kick in the butt
# Race car room: Run fast, did you win? Penalty: You get a pinch

from sys import exit
from Pirate import Pirate
from dayofdead import DayOfDead

class Room(object):

    def enter(self):
        print "Not yet configured.  Subclass and implement enter()"
        exit(1)   
#    def print_room(self):
#        print self.title 
        
#	def __str__( self):
#		return self.title        
        

class Dance(object): 

    def enter(self):
        print "A young girl shows you how to dance"
        print "Can you dance?"
        answer = raw_input("> ")
        if answer == "yes":
            print "Nice dance !!"
        else:
           print "Sorry !, you die.  Bye !"
           exit(1)  

class Race(object):

    def enter(self):
        print "Welcome to the race room"
        print "Ready?? Set, go !!  Did you win?"
        answer = raw_input("> ")
        if answer == "yes":
            print "Congrats !! You're done."
        else:
           print "Sorry !, you die.  Bye !"
           exit(1)  

class Child(object):

    def walks(self):
        pass
        
class Attendant(object):

    def quiz(self):
        pass
        
 
def main():
    print "Welcome to Frightmares"
    pirate = Pirate()
    day_of_dead = DayOfDead()
    dance = Dance()
    race = Race()
    
    pirate.enter()
    day_of_dead.enter()
    dance.enter()
    race.enter()
    
#        def play(self):
#    current_scene = self.scene_map.opening_scene()
    
#    room = Room(title="Pirate Room")
#    current_room = Pirate(room)
#    print current_room.enter()

#    rooms = {'pirate': Pirate(), 
#            'day_of_dead': DayOfDead(),
#            'dance' : Dance(),
#            'race' : Race() 
#            }
    
if __name__ == "__main__":
    main()
