/* Demonstrates calloc(). */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
     unsigned num;
     int *ptr;

     printf("Enter the number of type int to allocate: ");
     scanf("%d", &num);

     ptr = calloc(num, sizeof(int));

     if (ptr != NULL)
         puts("Memory allocation was successful.");
     else
         puts("Memory allocation failed.");
     return 0;
}
