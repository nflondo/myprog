/* Your first task is to write a function createStudent() that takes as inputs a 
string (namely a student's name) and an integer (their age) and that returns a 
pointer to a struct student which stores this information. Your function should 
dynamically allocate the memory required for this struct student and then write 
the student's name and age into this newly allocated memory. 
You are given the createStudent() function prototype and a main() function to 
test your code, please do not modify these:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
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