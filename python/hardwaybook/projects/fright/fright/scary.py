#!/usr/bin/python
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
    
        def __init__(self, name, description):
            self.name = name
            self.description = description
            self.paths = {}
            
        def go(self, direction):
            return self.paths.get(direction, None)
            
        def add_paths(self, paths):
            self.paths.update(paths)    
        

class Dance(object): 

    def enter(self):
        print "A young girl shows you how to dance"
        print "Can you dance?"
        answer = raw_input("> ")
        if answer == "yes":
            print "Nice dance !!"
            return 'race'
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
            exit(0)
        else:
           print "Sorry !, you die.  Bye !"
           exit(1)  

class Child(object):

    def walks(self):
        pass
        
class Attendant(object):

    def quiz(self):
        pass

class Engine(object):
    
    def __init__(self, scene_map):
        self.scene_map = scene_map

    def play(self):
        current_scene = self.scene_map.opening_scene()
        
        while True:
            print "\n-------------------"
            next_scene_name = current_scene.enter()
            current_scene = self.scene_map.next_scene(next_scene_name)
            
class Map(object):

    rooms = {'pirate': Pirate(), 
            'day_of_dead': DayOfDead(),
            'dance' : Dance(),
            'race' : Race() 
            }
    
    def __init__(self, start_scene):
        self.start_scene = start_scene
        
    def next_scene(self, scene_name):
        return Map.rooms.get(scene_name)
        
    def opening_scene(self):
        return self.next_scene(self.start_scene)                                               
 

a_map = Map('pirate')
a_game = Engine(a_map)
a_game.play()

#def main():
#    print "Welcome to Frightmares"
#    pirate = Pirate()
#    day_of_dead = DayOfDead()
#    dance = Dance()
#    race = Race()
    
#    pirate.enter()
#    day_of_dead.enter()
#    dance.enter()
#    race.enter()
    
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
    
#if __name__ == "__main__":
#    main()
