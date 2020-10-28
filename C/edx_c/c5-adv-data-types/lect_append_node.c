/* Append a node to a linked list
Try adding a fifth node...
*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit * next;
};
struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigitptr);

int main(void) {
    //! stack=showMemory(start=65520,cursors=[start,newDigitptr,end,tmp])
    struct digit *start, *newDigitptr, *end, *tmp;
    int first = 5;
    int second = 3;
    int third = 7;
    //int fourth = 8
    // Keep track of beginning and end of list
    start = createDigit(first);
    end = start;

    newDigitptr = createDigit(second);
    end = append(end, newDigitptr);
    
    newDigitptr = createDigit(third);
    end = append(end, newDigitptr);
    
    newDigitptr = createDigit(8);
    end = append(end, newDigitptr);
    
    // free needs to be added  here
    // start deleting nodes from beginning of the list using a tmp variable
    // to copy initial value and delete it later without losing next element
    tmp = start->next; // store next element into tmp
    free(start); // delete initial element
    
    start = tmp;
    tmp = start->next; // next element
    free(start);

    start = tmp;
    tmp = start->next;
    free(start);

    free(tmp);
    return 0;
}

struct digit * append(struct digit * end, struct digit * newDigitptr) {
    //! heap=showMemory(start=260, cursors=[end,newDigitptr])
    end->next = newDigitptr; // set next var to point to new element in list
    end = newDigitptr; // set end of list
    return(end);
}

struct digit * createDigit(int dig) {
    //! heap=showMemory(start=260, cursors=[ptr])
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}