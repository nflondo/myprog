// Create a sorted copy of a linked list
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit * readNumber(void); 
struct digit * searchNumber(struct digit * start, int number);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * reverseNumber(struct digit * start);
struct digit * sortedCopy(struct digit * start);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

int main(void) {
    //! showMemory(start=65520)
    struct digit *start, *backwards, *sorted;
    printf("Please enter a number: ");
    start = readNumber();
    printf("You entered: ");
    printNumber(start);
    printf("Backwards: ");
    backwards = reverseNumber(start);
    printNumber(backwards);
    printf("Sorted by digit:");
    sorted = sortedCopy(start);
    printNumber(sorted);
    freeNumber(start);
    freeNumber(backwards);
    freeNumber(sorted);
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

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

struct digit * searchNumber(struct digit * start, int number) {
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}

struct digit * reverseNumber(struct digit * start) {
    struct digit *ptr = start;
    struct digit *bstart = start;
    struct digit *newdigit;
    
    if (start!=NULL) {
        bstart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        newdigit = createDigit(ptr->num);
        bstart = insertAtFront(bstart, newdigit);
        ptr = ptr->next;
    }
    return(bstart);
}

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig) {
    // break the list, so need to keep track of two successive elements
    // this always returns the smallest number as the start of the list
    struct digit *ptr = start;
    struct digit *prev = NULL;
    // haven't reached end and number pointed by ptr is smaller than newDigit
    // terminates when end of the list or ptr->num is bigger
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr; // save current pointer
        ptr = ptr->next; 
    }
    if (prev == NULL) {
        start = insertAtFront(start, newDig);  // new start of list
    } else {
        prev->next = newDig; // break the connection here
        newDig->next = ptr; // works if in middle or end of linked list
    }
    return(start);
}

struct digit * sortedCopy(struct digit * start) {
    //! heap1=showMemory(start=348, cursors=[start, ptr, sortedStart, newDigit])
    //! heap2=showMemory(start=519, cursors=[start, newDigit, ptr, prev])
    struct digit *ptr = start;
    struct digit *sortedStart = NULL;
    struct digit *newDigit;
    
    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr!=NULL) { // go through list and sort each element
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}