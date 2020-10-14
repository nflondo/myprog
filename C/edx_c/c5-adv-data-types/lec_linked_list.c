/* Link structures together in a linked list.
Linked lists allow you to create a list of elements of type struct, 
but don't put it in array.   Can move from one element to the  next via memory 
location .
*/
#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next; // this element is of type struct point
};

int main(void) {
    //! showMemory(start=65520)
    // populating structures without malloc() in this example
    struct point pt1 = {1, 2, NULL};
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    struct point * start, * ptr; // Declare a start and a ptr
    
    start = &pt1; // set start to first element in the list
    pt1.next = &pt2; // set second and third elements
    pt2.next = &pt3;
    
    ptr = start; 
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
	return 0;
}
