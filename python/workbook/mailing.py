#!/usr/bin/python3
# Display name and complete mailing address
name="Nefi Munoz"
street="1431 S 730 W"
city="Payson"
state="UT"
zip=84651
print("%s\n%s\n%s, %s %d" %(name, street, city, state, zip))

#Area of a room
width=float(input("Enter width of room (ft): "))
length=float(input("Enter length of room (ft): "))
#area
area = width * length
print("Area of your room is: %.2f square ft" % area)