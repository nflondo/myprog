#!/usr/bin/python
# Main

import json
from classes.car import Car

def main():
    mycar = Car(make="Mazda", model="6", transmission="automatic", color="blue", doors=4, features={"stowaway_seats":False})
    f = open('newcar.json', 'w')
    json.dump(vars(mycar), f, indent=2)
    f.close()

if __name__ == "__main__": 
	main()
