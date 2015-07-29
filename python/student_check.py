#!/usr/bin/python
# Check if a name is in a class

def check_student(name):
    myClass = ['anna','benjamin','liliana','samuel']
    
    for student in myClass:
        if student == name:
            return True
            break
    
    return False

def main():
    while True:
        name = raw_input("Give me the name of a student: Enter 'q' to quit: ")
        if name == 'q':
            print "Good Bye"
            break
        while name.isdigit():
            print "I'm sorry but {0} isn't valid.".format(name)
            name = raw_input("Give me the name of a student: Enter 'q' to quit: ")
        print "Thanks.  The name you gave me is {0}".format(name)
        if check_student(name):
            print "Student is present"
        else:
            print "Student is not present"
            
            

if __name__ == "__main__":
    main()
    


    
