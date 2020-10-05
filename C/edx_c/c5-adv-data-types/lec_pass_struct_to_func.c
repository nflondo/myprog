/* Pass structures to functions directly.
This passes a copy of the whole structure (object) which for a big struct may be
too much.
*/
#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
// Prototype uses struct so it has to be put after the struct
void printStudent(struct student stud);

int main(void) {
	//! showMemory(start=65520)
	struct student me={"Petra", "Bonfert-Taylor", 1989, 3.5};
	struct student you={"Remi", "Sharrock", 2005, 3.5};
	
	printStudent(me);
	printStudent(you);
	return 0;
}

void printStudent(struct student stud){ // takes whole struct variable, but can't mod
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}