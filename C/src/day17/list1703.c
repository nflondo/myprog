/* The assert() macro. */

#include <stdio.h>
#include <assert.h>

int main(void)
{
     int x;

     printf("\nEnter an integer value: ");
     scanf("%d", &x);

     assert(x >= 0);
     printf("You entered %d.\n\n", x);
     return 0;
}
