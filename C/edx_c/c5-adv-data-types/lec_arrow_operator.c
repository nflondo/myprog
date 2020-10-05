/* Pass structures to functions with pointers.
(*studptr).lastName is equal to studptr->firstName
*/ 
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student);
void readStudent(struct student *studptr);

int main(void) {
   //! showMemory(start=65520)
    struct student me;
    readStudent(&me); // pass address of var me
    printStudent(me);
	return 0;
}

void readStudent(struct student *studptr) { //takes a pointer
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    // -> dereferences first, the accesses the element/variable
    // Don't need & to stick value into strings, but need it for digits and floats
    scanf("%s", studptr->firstName); //dereference the pointer to get to value

    printf("Last name: ");
    scanf("%s", studptr->lastName);
    
    printf("Birth year: ");
    // Do need & to stick value into d, floats
    scanf("%d", &studptr->birthYear); //here & is needed
    
    printf("Average grade: ");
    scanf("%lf", &studptr->aveGrade);
}

void printStudent(struct student stud) {
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}