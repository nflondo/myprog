#!/usr/bin/python
# how to print

class Test(object):
    def __init__(self, word, num):
        self.word = word
        self.num = num
    
    def __str__(self):
        return "Values in this object:\
 word = {word}, num = {num}".format(word=self.word,num=self.num)
 
def main(): 
    a = Test(word="Hello", num=10) 
    print a 

if __name__ == "__main__": 
    main()
