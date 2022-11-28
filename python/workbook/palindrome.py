#!/usr/bin/python3
# Read a string from user and determine whether or not it is a palindrome.

def is_palindrome(word):
    max_index = (len(user_word) - 1)    
    for i in range(len(user_word)):
        if user_word[i] != user_word[(max_index - i)]:
#            print("Not a palindrome")
            return False

    return True

user_word = input("Enter a word to see if it's a palindrome: ")
if is_palindrome(user_word):
    print("\"%s\" is a palindrome" % user_word)
else:
    print("\"%s\" is NOT a palindrome" % user_word)
