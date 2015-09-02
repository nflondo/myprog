#!/usr/bin/python
# class that test for greater than between objects
import pdb

class Mygte( object):
    def __init__( self, num):
        self.num = num 

    def __ge__( self, other):
        if self.num >= other.num:
            print "True"
            return True
        else:
            print "False"
            return False


def main():
    pdb.set_trace() 
    a = Mygte(5)
    b = Mygte(5)
    c = Mygte(7)

    a >= b
    a >= c
    c >= a

if __name__ == "__main__": 
    main()
