#!/usr/bin/python
# number-guessing game

import random 
import pdb
# pdb.set_trace() below will cause the program to stop at that point and start the debugger
pdb.set_trace()

guessesTaken=0
secret_num = random.randint(1,10) 
print "Secret number: {0}".format(secret_num)
print "I have a number..."

#while True:
while guessesTaken < 3:
	guess = raw_input("What is your guess [1-10]?: Enter '0' to quit: ")
	print "My guess: {0}".format(guess)
	while not guess.isdigit():
		print "I'm sorry but \"{0}\" isn't valid.".format(guess)
		guess = raw_input("What is your guess [1-10]?: Enter '0' to quit: ")
	
	guess = int(guess)
	guessesTaken = guessesTaken +1
	if guess == 0:
		print "Good Bye"
		break
	
	#pdb.set_trace() 
	if guess > secret_num:
		print "That's too high.  Try again !"
	elif guess < secret_num:
		print "That's too low.  Try again !"
	else:
		print "You got it !! Thanks for playing !!"
		break 







