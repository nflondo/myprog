from sys import exit
# You're in a spooky house, which way will you go, will you make it out alive, 
# with dry pants, with  a raspy voice and will you find a dead body?

def dead(why):
    print why, "Hasta la vista!"
    exit(0)

def dead_room():
    """"Here you find a dead body"""
    print "You walk into a pirate treasure with dead bodies around it"
    print "Will you take any gold coins? (y/n)"
       
    next = raw_input("> ")
    
    if next == "y":

        good_input = False 
        while good_input == False:
            print "How many coins will you take?"
            next = raw_input("> ")
            try:
                how_much = int(next)
                if how_much < 50:
                    print "Nice, you're not greedy, you win!"
                    # This exits with rc = 0 which is good exit
                    exit(0)
                else:
                    dead("You greedy bastard!")

                good_input = True
            except ValueError:
                print("That's not an integer")
      
    
    elif next == "n":
        print "Good ! no harm happens to you.  Go on"   
        
    else:
        print "Invalid entry"             
    
    
def saw_room():

    print "A man with a chain saw is coming to get you"
    print "Will you run or punch the man (run/punch)?"
#    bear_moved = False
    
    while True:
        next = raw_input("> ")
        
        if next == "run":
            print "Running might save you"
            break
 #       elif next == "punch" and not bear_moved:
        elif next == "punch":
            print "A fist is not match for a saw, sorry you just lost a leg"
            print "and have to exit the spooky house.  Bye !!"
            exit(1)
        else:
            print "I got no idea what that means."
    
def start():
    """ Valid answers are 'left' and 'right'"""
    print "You are in a spooky house."
    print "There is a door to your right and left."
    print "Which one do you take? (left or right)"
    
    next = raw_input("> ")
    
    if next == "left":
        saw_room()
    elif next == "right":
        dead_room()
    else:
        dead("You stumble around the room until you starve.")
        
start() 
