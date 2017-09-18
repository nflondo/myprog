from sys import exit
from random import randint

class Scene(object):

    def enter(self):
        print "Not yet configured.  Subclass and implement enter()"
        exit(1)
            
class Engine(object):

    def __init__(self, scene_map):
        self.scene_map = scene_map
        
    def play(self):
        current_scene = self.scene_map.opening_scene()
        
        while True:
            print "\n---------------"
            next_scene_name = current_scene.enter()
            current_scene = self.scene_map.next_scene(next_scene_name)
            
class Death(Scene):

    quips = [
        "You died.  You kinda suck at this."
    ]
    
    def enter(self):
        print Death.quips[randint(0, len(self.quips)-1)]
        exit(1)
        
class CentralCorridor(Scene):
    
    def enter(self):
        print "Gothons have invaded your ship."
        print "Your mission is to get to Weapons Armory"
        print "You're in the central corridor, a gothon jumps in front of you"
        
        action = raw_input("> ")
        
        if action == "shoot!":
            print "You fire at the gothon but missed"
            return 'death'
            
        elif action == "dodge!":
            print "nice try, Gothon gets you"            
            return 'death'
            
        elif action == "tell a joke":
            print "Gothon laughs and can't control himself"
            return 'laser_weapon_armory'
            
        else:
            print "DOES NOT COMPUTE!"
            return 'central_corridor' 
            
class LaserWeaponArmory(Scene):

    def enter(self):
        print "Get the code !! it's 3 digits"
        code = "%d%d%d" % (randint(1,9), randint(1,9), randint(1,9))
        guess = raw_input("[keypad]> ")
        guesses = 0
        
        while guess != code and guesses < 10:
            print "BZZZZEDDD!"
            guesses += 1
            guess = raw_input("[keypad]> ")
            
        if guess == code:
            print "You grab the neutron bomb"
            return 'the_bridge'
        else:
            print "The mechanism fuses together, you die"
            return 'death'
            
class TheBridge(Scene):

    def enter(self):
        print "You burst onto the bridge, Gothons are afraid of you"
        
        action = raw_input("> ")
        
        if action == "throw the bomb":
        
            print "In a panic you throw the bomb at the Gothons, but it kills you too"
            return 'death'
            
        elif action == "slowly place the bomb":
            print "You point your blaster at the bomb under your arm"
            return 'escape_pod'
        else:
            print "DOES NOT COMPUTE!"
            return "the_bridge"
            
class EscapePod(Scene):

    def enter(self):
        print "There are 5 pods, which one do you take?"
        
        good_pod = randint(1,5)
        guess = raw_input("[pod #]> ")
        
        if int(guess) != good_pod:
            print "This is a broken pod, you die"
            return 'death'
            
        else:
            print "Good choice, you won !!"
            
            return 'finished'
            
class Map(object):

    scenes = {
        'central_corridor': CentralCorridor(),
        'laser_weapon_armory': LaserWeaponArmory(),
        'the_bridge': TheBridge(),
        'escape_pod': EscapePod(),
        'death': Death()
    }
    
    def __init__(self, start_scene):
        self.start_scene = start_scene
        
    def next_scene(self, scene_name):
        return Map.scenes.get(scene_name)
        
    def opening_scene(self):
        return self.next_scene(self.start_scene)                                                

# Main 
# Creates a Map object which takes a Scene 
a_map = Map('central_corridor')

# Creates an Engine object which takes a Map object
a_game = Engine(a_map)
a_game.play()                                                                                                
            
                                                             
                                                        
