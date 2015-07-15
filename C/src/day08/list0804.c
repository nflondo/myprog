/* Passing an array to a function. */

#include <stdio.h>

#define MAX 10

int array[MAX], count;

int largest(int x[], int y);

int main(void)
{
     /* Input MAX values from the keyboard. */

     for (count = 0; count < MAX; count++)
     {
	 printf("Enter an integer value: ");
	 scanf("%d", &array[count]);
     }

     /* Call the function and display the return value. */
     printf("\n\nLargest value = %d\n", largest(array, MAX));

     return 0;
}
/* Function largest() returns the largest value */
/* in an integer array */

int largest(int x[], int y)
{
     int count, biggest = -12000;

     for ( count = 0; count < y; count++)
     {
	 if (x[count] > biggest)
	     biggest = x[count];
     }

     return biggest;
}

