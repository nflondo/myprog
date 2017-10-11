#!/usr/bin/python
from nose.tools import *
#from frightmares.scary import Map

def setup():
    print "SETUP!"
    
def teardown():
    print "TEAR DOWN !"
    
def test_basic():
    print "I RAN!"  
    
def test_map():
#    pass
    myroom = Map('pirate')
    
    assert_equal(myroom.start_scene, "pirate")    
