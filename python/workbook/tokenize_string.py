#!/usr/bin/python3
# convert a string into tokens, tokens are items such as operators, numbers, and
# parentheses.  Operators are: *,/,^,-and+
# each token should be a parenthesis, an operator, or a number.  Any sequence
# of consecutive digits should be treated as one number token
import re

def string_to_token(user_string):    
    more_than_one_digit = False
    token_list=[]
    num = ""
    digit = 0
    for i in range(0, len(user_string)):
        if re.fullmatch('[\*\-\+\/\(\)\=]',user_string[i]):
            if digit > 0:
                token_list.append(num)
                digit = 0
                num=""
            token_list.append(user_string[i])  
#            print("'[\*\-\+\/\(\)\=]',user_string[i]: %s" %user_string[i])
#            print("digit: %d" %digit)            
        elif re.fullmatch('[0-9]',user_string[i]): 
#            print("[0-9]',user_string[i]): %s" % user_string[i])           
            num = num + user_string[i]
#            print("[0-9]'...num: %s" % num) 
#            token_list.append(num)
            digit = digit + 1  
#            print("digit: %d" %digit)          
            if i == (len(user_string)-1):
                token_list.append(num)       
    return token_list

def main():
    user_input = input("Enter a math expression: ")
    result = string_to_token(user_input)
    print(result)
    

if __name__ == "__main__":
    main()