/*Get the size of a structure in memory.
Memory footprint of a struct = size of components inside struct plus some padding
depending on compiler .
*/
#include <stdio.h>

struct student{
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;
};

int main(void) {
    //! showMemory(start=65520)
	struct student me;
    printf("Size of struct student is %zu.\n", sizeof(struct student));
    printf("Size of firstName is %zu.\n", sizeof(me.firstName));
    printf("Size of lastName is %zu.\n", sizeof(me.lastName));
    printf("Size of birthYear is %zu.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %zu.\n", sizeof(me.aveGrade));

	return 0;
}
