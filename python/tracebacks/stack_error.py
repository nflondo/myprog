#!/usr/bin/python
# Program to produce a stack trace

class Alpha(object):
    def __init__(self):
        self.one = "One"
        self.two = "Two"

    def __str__(self):
        return self.one + " " + self.two

def print_object(obj):
    print obj

def main():
    object_a = Alpha()
    print_object(object_a)

if __name__ == '__main__':
    main()

