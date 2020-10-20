/* Create a node of a linked list.
An int has a size limit, but you can create a large digit using a linked list
where the only limit is the available memory.  Operations on the digit would be
different of course.
*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit * next;
};
struct digit * createDigit(int dig);

int main(void) {
    //! stack=showMemory(start=65520, showcursor[numberptr])
    struct digit * numberptr;
    int digitToStore = 5; // initial number/digit
    numberptr = createDigit(digitToStore);
    printf("We are storing the digit %d and the pointer %p at memory location %p.\n", 
        numberptr->num, numberptr->next, numberptr);
    free(numberptr);
    return 0;
}

struct digit * createDigit(int dig) {
    //! heap=showMemory(start=330, cursors=[ptr])
    // malloc() calls reserve memory in the heap
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}