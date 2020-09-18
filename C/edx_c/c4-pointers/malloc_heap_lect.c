/* Malloc() does dynamic memory allocation and this happens in lower
memory addresses in the "heap" area (higher addresses is the "stack") near program
code.
Heap: Memory dynamically allocated during a process runtime. 
*/
#include <stdlib.h>
int main(void){
    //! showMemory(start=272)
    int * intptr; // pointer holds the location of memory that has been reserved
    double * doubleptr;
    intptr = (int *) malloc(sizeof(int));//(int *) is good practice. Helps malloc()
    * intptr = 5; //Dereferencing the pointer giving it value 5
    doubleptr = (double *) malloc(sizeof(double)); //(double *) is good practice
    * doubleptr = 9.0;
    return 0;
}