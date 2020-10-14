/* Allocate memory for structures
*/
#include <stdio.h>
#include <stdlib.h>  // needed for malloc() calls
struct point{
    int x;
    int y;
};
void printPoint(struct point pt);
void readPoint(struct point * ptr);
void printPoly(struct point *ptr, int vertices);

int main(void) {
    //! showMemory(start=65520)
    struct point * polygon; // declare a pointer to hold a malloc() call
                            // but not initialize yet
    int i, num;
    printf("How many vertices does your polygon have? ");
    scanf("%d", &num);
    // Initialize polygon here based on number of vertices (num) is the size
    // of the malloc() reservation
    polygon = (struct point *) malloc(num * sizeof(struct point));

    for (i=0; i<num; i++){
        readPoint(&polygon[i]); //needs address of polygon at [i]
    }
    printPoly(polygon, num);
    free(polygon); // free memory here
	return 0;
}

void readPoint(struct point * ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x); // storing a digit
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printPoly(struct point * ptr, int vertices) {
    int i;
    for (i=0; i<vertices; i++) {
        printPoint(ptr[i]); // pointer to struct, but printPoint just takes
                        // struct, how is it working?
    }
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}