
def fill_list():
    i = 0
    numbers = []
    end = 6
    while i < end:
        print "At the top i is %d" % i
        numbers.append(i)
        
        i = i + 1
        print "Numbers now: ", numbers
        print "At the bottom i is %d" %i
    
    #print "The numbers: "
    return numbers

#    for num in numbers:
#        print num    
 
fill_list() 
#mylist=fill_list()
#print "My list: %r" % mylist
        
