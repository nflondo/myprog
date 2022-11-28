#!/usr/bin/python3
# Check if a list contain a sublist
# sublist definition: emtpy list, copy of list itself, single elements in the list,
# adjacent elements in list.

from re import sub

def isSublist(larger, smaller):
    '''Takes two lists and returns True if and only if smaller is a sublist of
    larger
    '''    
    # check for empty list
    if len(smaller) == 0:
        return True
    # check if single element is found in main list
    if len(smaller) == 1:
        for element in smaller:
            if element in larger:
                print("found")
                return True
            else:
                print("not found")
                return False
    # when sublist has more than 1 element check if adjacent is in main list
    else:
        index = -1
        # iterate over sublist
        for element in smaller:
            # if first elemet in sublist is found in main list
            if element in larger:
                print('element:' , element)
                if index == -1:
                    # find location of element in main list
                    index = larger.index(element)
                    print('index: ', index)
                    previous = element
                    print('previous: ', previous)
                else:
                    if element != larger[index + 1]:
                        return False
            else:
                return False                
    return True

def main():
    main_list=[1,2,3,4]
    sublist=[2]
    sublist2=[5]
    sublist3 = [1,4]
    print('len sublist3:', len(sublist3))
    if isSublist(main_list,sublist):
        print('Sublist ', sublist, ' is Found in main list' )
    if isSublist(main_list, sublist2):
        print('Sublist ', sublist2, ' is Found in main list' )
    if isSublist(main_list, sublist3):
        print('Sublist ', sublist3, ' is Found in main list' )

if __name__ == "__main__":
    main()