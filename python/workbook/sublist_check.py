#!/usr/bin/python3
# Check if a list contain a sublist
# sublist definition: emtpy list, copy of list itself, single elements in the list,
# adjacent elements in list.

from re import sub


def isSublist(larger, smaller):
    '''Takes two lists and returns True if and only if smaller is a sublist of
    larger
    '''
    for element in smaller:
        if element in larger:
            print("found")
        else:
            print("not found")

def main():
    main_list=[1,2,3,4]
    sublist=[2]
    sublist2=[5]
    isSublist(main_list,sublist)
    isSublist(main_list, sublist2)

if __name__ == "__main__":
    main()