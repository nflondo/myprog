#!/usr/bin/python3
# Generate all sublists of a list
# empty list[], single element, multiple elements as long as they're next to 
# each other (adjacent)

def all_sublists(main_list):
    #extract all sublists from main list
    result = []
    # empty list
    result.append([])
    # add adjacent elements as sublists
    step = 0
    while step < len(main_list):
        #range(start indice included, stop index not included)
        for index in range(step, len(main_list)):
            #list slicing creates a new list[index start:index stop not included]
            result.append(main_list[step:index + 1])
        step = step + 1 #move to next number in the list

    return result    

def main():
    user_list = []
    user_input = input("Enter elements of a list (separated by a space): ")
    user_list = user_input.split()
    result = all_sublists(user_list)
    print("Original List: {}".format(user_list))
    print("Sublists: {}".format(result))

if __name__ == "__main__":
    main()