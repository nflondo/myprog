/* Activity: append a node with student data
In this task you will continue working on the linked list of students in which 
you would like to store, for each student, their name and age. As before you are 
provided with some code that you should not modify:
    A structure definition for the storage of each student's information.
    A main() function to test your code. 
    Prototypes for the functions createStudent() (from the previous task) and 
    append() (from the current task).
You will need the function definition (from the previous task) for createStudent(),
 as well as any other functions you added, such as copyStr() for example. If you 
 were unable to solve the previous task you have the option to be given the code 
 for the createStudent() function (see the quiz preceding this task) so that you
  can work on the current task.
Your new task is to write a function append() which takes as input two pointers:
 the first pointer holds the address of the current end of the linked list of 
 students, the second pointer points to a newly created student. Your function 
 should append this new student to the linked list and return the address 
 (a struct student *) of the new end of the list. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strCpy

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
/* add other prototypes here if needed */

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

    return 0;
}

struct student *append(struct student * end, struct student * newStudptr){
    //struct student *ptr;
    //ptr = (struct student *)malloc(sizeof(struct student));
    //ptr = end;
    //ptr->next=newStudptr;
    end->next=newStudptr;
    end = newStudptr;
    return end;
} 

struct student *createStudent(char studentName[], int studentAge){
    //printf("studentName in funct: %s\n", studentName);
    struct student * ptr;
    ptr = (struct student *)malloc(sizeof(struct student));
    //ptr->name = studentName; This doesn't work because:
    /*
    "coz if you printf("%p %p", ptr->name, studentName); they both are different
    memory location address coz they both are char pointer not a normal variable
    like char a = 'p' so you need to derefernce first so you can access the value
    which is pointed on that address if you write like this *ptr->name = *studentName;
    then it will copy only the first letter coz they both are pointing on 0 th 
    possition of their allocated memory"
    
    "mike.name is a character array. You can't copy arrays by just using 
    the = operator.  Instead, you'll need to use strncpy or something similar 
    to copy the data"
    https://stackoverflow.com/questions/18966979/c-struct-initialization-with-char-array/18967087
    https://www.cs.swarthmore.edu/~newhall/cs31/resources/C-structs_pointers.php
    */
    strcpy(ptr->name, studentName);
    ptr->age = studentAge;
    ptr->next = NULL;
    return ptr;
}
/* Place your function definitions here. Be sure to include the definition for 
   createStudent() and any other functions you created for the previous task. */
