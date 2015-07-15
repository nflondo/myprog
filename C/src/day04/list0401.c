/* Demonstrates a simple function */
#include <stdio.h>

long cube(long x);

long input, answer;

int main(void)
{
   printf("Enter an integer value: ");
   scanf("%ld", &input);
   answer = cube(input);
   /* Note: %ld is the conversion specifier for */
   /* a long integer */
   printf("\nThe cube of %ld is %ld.\n", input, answer);
  
   return 0;
}

/* Function: cube() - Calcs the cubed value of a variable */
long cube(long x)
{
   long x_cubed;

   x_cubed = x * x * x;
   return x_cubed;
}
