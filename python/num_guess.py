#!/usr/bin/python
# number-guessing game

import random 
import pdb
secret_num = random.randint(1,10) 
print "Secret number: {0}".format(secret_num)
print "I have a number..."

while True:
    guess = raw_input("What is your guess [1-10]?: Enter 'q' to quit: ")
    guess=guess.strip()
    int(guess)
    if guess == 'q':
        print "Good Bye"
        break
    while not guess.isdigit():
        print "I'm sorry but {0} isn't valid.".format(guess)
        guess = raw_input("What is your guess [1-10]?: Enter 'q' to quit: ")
        int(guess)
    #print "Thanks.  Your age is set to {0}".format(age)
    pdb.set_trace() 
    if guess > secret_num:
        print "That's too high.  Try again !"
    elif guess < secret_num:
        print "That's too low.  Try again !"
    else:
        print "You got it !! Thanks for playing !!"
        #return 







