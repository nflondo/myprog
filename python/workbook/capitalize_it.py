#!/usr/bin/python3
# create a function that takes a string as its only parameter and returns a
# new copy of the string that has been correctly capitalized
# - capitalize the first non-space character in the string
# - capitalize the first non-space character after a period, exclamation mark
# or question mark, and
# - capitalize a lowercase "i" if it is preceded by a space and followed by a space,
# period, exclamation mark, question mark or apostrophe.
# Include a main program that reads a string from the user, capitalized=s it using 
# your function, and displays the result.
import re

def capitalize_it(sentence):
    #create a copy 
    result = sentence
    # Capitalize the first non-space character in the string
    pos = 0
    while pos < len(sentence) and result[pos] == " ":
        pos = pos + 1
        
#    print("pos:", pos)

    if pos < len(sentence):
        # Replace the character with its uppercase version without changing any
        # other characters
        result = result[0 : pos] + result[pos].upper() + result[pos + 1 : len(result)]

    # Capitalize the first letter that follows a ".", "!", or "?"
    pos = 0
    while pos < len(sentence):
        if result[pos] == "." or result[pos] == "!" or result[pos] == "?":
            # Move past the ".", "!", "?"
            pos = pos + 1
            # Move past any spaces
            while pos < len(sentence) and result[pos] == " ":
                pos = pos + 1
            # If we haven't reached the end of the string then replace the current
            # character with its uppercase equivalent
            if pos < len(sentence):
                result = result[0: pos] + result[pos].upper() + \
                    result[pos + 1: len(result)]
        # Move to the next character
        pos = pos + 1

    # Capitalize i when it is preceded by a space and followed by a space, period,
    # exclamation mark, question mark or apostrophe
    pos = 1
    while pos < len(sentence) - 1:
        if result[pos - 1] == " " and result[pos] == "i" and \
            (result[pos + 1] == " " or result[pos + 1] == "." or \
            result[pos + 1 == "!" or result[pos + 1 ] == "?" or \
            result [pos + 1] == "'"]):
            # Replace the i with an I without changing any other characters
            result = result[0 : pos] + "I" + result[pos + 1 : len(result)]
        pos = pos + 1

    return result

def main():
    user_input = input("Enter some text to capitalize: ")
    capitalized = capitalize_it(user_input)
    print("It is capitalized as: ", capitalized)

if __name__ == "__main__":
    main()