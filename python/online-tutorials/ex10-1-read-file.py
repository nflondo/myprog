#!/usr/bin/env python3

filename = '/tmp/Server_Reduced-20200806-110059.tsf'

myList = []  # the list to store results
lineNum = 0
substr = "[SUT IP Address]".lower() # substring to search for
secondSubstr = "Station IP Address".lower() # second search term

with open(filename, 'rt') as myfile:
    for line in myfile:
        lineNum += 1
        if line.lower().find(substr) != -1: # case-insensitive match
            if substr != secondSubstr:
                substr = secondSubstr            
                myList.append("Line " + str(lineNum) + ": " + line.rstrip('\n'))
            else:
                myList.append("Line " + str(lineNum) + ": " + line.rstrip('\n'))
                break

for match in myList:
    print(match)

equalSignPosition = myList[1].find("=") # find position of equal sign
sutIpAddr = myList[1][equalSignPosition + 1:] # get part of the string
print(sutIpAddr) # debug printing

# reads entire file and prints entire file
#with open(filename) as file_object:
#    contents = file_object.read()
#    print(contents)

# reads entire file prints it with a loop over the file object    
#with open(filename) as file_object:
#    for line in file_object:
#        print(line.rstrip())
#        print(line)
#print("--")

# reads and stores file in a list, then prints the list        
#with open(filename) as file_object:
#    lines_list = file_object.readlines()
    
#for line in lines_list:
#    print(line.rstrip())    
