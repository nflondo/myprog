/* Demonstrates structures that contain other structures. */

/* Receives input for corner coordinates of a rectangle and
   calculates the area. Assumes that the y coordinate of the
   lower-right corner is greater than the y coordinate of the
   upper-left corner, that the x coordinate of the lower-
   right corner is greater than the x coordinate of the upper-
   left corner, and that all coordinates are positive. */

#include <stdio.h>

int length, width;
long area;

struct coord{
     int x;
     int y;
};

struct rectangle{
     struct coord topleft;
     struct coord bottomrt;
} mybox;

int main(void)
{
     /* Input the coordinates */

     printf("\nEnter the top left x coordinate: ");
     scanf("%d", &mybox.topleft.x);

     printf("\nEnter the top left y coordinate: ");
     scanf("%d", &mybox.topleft.y);

     printf("\nEnter the bottom right x coordinate: ");
     scanf("%d", &mybox.bottomrt.x);

     printf("\nEnter the bottom right y coordinate: ");
     scanf("%d", &mybox.bottomrt.y);

     /* Calculate the length and width */

     width = mybox.bottomrt.x - mybox.topleft.x;
     length = mybox.bottomrt.y - mybox.topleft.y;

     /* Calculate and display the area */

     area = width * length;
     printf("\nThe area is %ld units.\n", area);

     return 0;
}
