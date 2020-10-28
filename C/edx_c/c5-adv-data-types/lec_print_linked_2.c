/* Print a linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);

int main(void) {
    //! stackk = showMemory(start=65520)
    struct digit *start, *newDigptr, *end, *tmp;
    int first = 5, second = 3, third = 7, fourth = 8;
    start = createDigit(first);
    end = start;
    newDigptr = createDigit(second);
    end = append(end, newDigptr);
    newDigptr = createDigit(third);
    end = append(end, newDigptr);
    newDigptr = createDigit(fourth);
    end = append(end, newDigptr);

    printNumber(start); // pass start of linked list to printNumber func
    // Delete steps
    tmp = start->next; // 1- set tmp to second element (Advance tmp)
    free(start); // 2- free first element (Delete start)
    start = tmp; // 3- set start to second element (Advance start)
    tmp = start->next; // 4- set tmp to third element (Advance tmp)
    free(start); // 5- free second element (Delete start)
    //free(tmp); // 6- free third element (Delete tmp)
    start = tmp;      // 7- (Advance start)
    tmp = start->next; // 8 - (Advance tmp)
    free(start); //9- free third element (Delete start)
    free(tmp);  // 10 - free fourth element (Delete tmp)

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start){
    //! heap=showMemory(start=277, cursors=[ptr,start])
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next; // advance to next element
    }
    printf("\n");
}