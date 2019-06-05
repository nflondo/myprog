/* Demonstrates basic pointer use. */

#include <stdio.h>

/* Declare and initialize an int variable */

int var = 1;

/* Declare a pointer to int */

int *ptr;

int main(void)
{
     /* Initialize ptr to point to var */

     ptr = &var;

     /* Access var directly and indirectly */

     printf("\nDirect access, var = %d", var);
     printf("\nIndirect access, var = %d", *ptr);

     /* Display the address of var two ways */

     printf("\n\nThe address of var = %lu", (unsigned long)&var);
     printf("\nThe address of var = %lu\n", (unsigned long)ptr);

     return 0;
}
