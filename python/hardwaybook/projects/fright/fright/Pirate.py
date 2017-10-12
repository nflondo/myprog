class Pirate(object):
    def enter(self):
        print "A big scary woman pirate with one eye receives you."
        print "She has a parrotkid in her shoulder and is surrounded by a coffin"
        print "full of gold.  She asks: What does a pirate say?"
        
        answer = raw_input("> ")
        if answer == "arrg":
            print "You know pirates !!"
            return 'day_of_dead'
            
#        elif action == "dodge!":
#            print "nice try, Gothon gets you"            
#            return 'death'
            
#        elif action == "tell a joke":
#            print "Gothon laughs and can't control himself"
#            return 'laser_weapon_armory'
            
        else:
            print "Wrong !, you die.  Bye !"
            exit(1)   
#            return 'central_corridor' 
