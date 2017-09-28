class DayOfDead(object): 

    def enter(self):
        print "A nice looking skeleton woman with a big dress is standing in"
        print "Front of you. You can see food offerings on a table, and "
        print "Grandma and grandpa's bones sitting on chairs"
        print "How do you say \"dead\" in spanish?" 
        answer = raw_input("> ")
        if answer == "muerto":
            print "Good Job !!"
        else:
           print "Wrong !, you die.  Bye !"
           exit(1)  
