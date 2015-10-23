#!/usr/bin/python
# Class for object car

class Car(object):
    def __init__(self, make, model, transmission, color, doors=4, features={}):
        self.make = make
        self.model = model
        self.transmission = transmission
        self.color = color
        self.doors = doors
        self.features = features
