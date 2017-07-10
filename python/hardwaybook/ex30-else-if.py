people = 30
cars = 40
buses = 15

if cars > people and people > buses:
    print "We could take the cars or the buses."
    print "Cars: %d Buses: %d People: %d" %(cars, buses, people) 
elif cars < people:
    print "We should not take the cars."
else:
    print "We can't decide."
    
if buses > cars:
    print "That's too many buses."
elif buses < cars:
    print "Maybe we could take the buses."
else:
    print "We still can't decide."
    
if people > buses:
    print "Alright, let's just take the buses."
else:
    print "Fine, let's stay home then."                        
        
