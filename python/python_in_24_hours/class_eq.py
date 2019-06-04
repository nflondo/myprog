#!/usr/bin/python
# class that test for equality and inequality of an object
import pdb
class Test( object):
    def __init__( self, num):
        self.num = num
    
    def __eq__( self, other):
        if self.num == other.num:
            print "True"
            return True
        else:
            print "False"            
            return False
    def __ne__( self, other):
        if self.num != other.num:
            print "True"
            return True
        else:
            print "False"
            return False

def main(): 
    pdb.set_trace()
    a = Test(5)
    b = Test(5)
    c = Test(7)

    a != b
    a != c

if __name__ == "__main__": 
    main()
