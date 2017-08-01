
def fill_list(end, increment):
    i = 0
    numbers = []
#    end = 6
    while i < end:
        print "At the top i is %d" % i
        numbers.append(i)
        
        i = i + increment
        print "Numbers now: ", numbers
        print "At the bottom i is %d" %i
    
    #print "The numbers: "
    return numbers


mylist=fill_list(4, 1)
print "My list: %r" % mylist
        
mylist=fill_list(6, 2)
print "My list: %r" % mylist        
