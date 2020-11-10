/* Activity: count redundancies in number.
Your task is to write a new function countRedun() which takes as input a pointer
that holds the address of the start of a linked list of digits. Your function 
should count how many redundancies can be observed in the number stored in this
list and return this count of redundancies. A redundancy is a digit which has 
previously already occurred in the number. For example, in the number 39534, 
the second '3' is a redundancy.

This task offers 2 hints :
Hint 1 :
One way to solve this problem is to create a sorted copy of the linked list and 
count redundancies in this copy - it's easier in a sorted list. Just remember to
 free your sorted copy after its use.
Hint 2 :
In a sorted linked list of digits, a redundancy occurrs for each digit that 
equals the previous digit.
*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);
int countRedun(struct digit * start);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * sortedCopy(struct digit * start);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

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

struct digit *readNumber(void) {
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

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}
struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
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
// Write your countRedun() function here
int countRedun(struct digit * start){
    struct digit *ptr = start;
    struct digit *sorted;
    struct digit *prev = NULL;
    sorted = sortedCopy(ptr);
    
    int sum = 0;
    while (sorted->next != NULL){ // check if next element in list is null otherwise
                                // get segmentation fault
        prev = sorted; // save current element
        sorted = sorted->next;
        //    ptr->num = 9;
        //printf("prev->next: %d sorted->next %d: \n",prev->num, sorted->num);
        if(sorted->num==prev->num)sum ++;            
        //}        
    }
    freeNumber(sorted);
    return(sum);
}


