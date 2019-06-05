/* Demonstrates the numeric nature of char variables */

#include <stdio.h>

/* Declare and initialize two char variables */

char c1 = 'a';
char c2 = 90;

int main(void)
{
     /* Print variable c1 as a character then as a number */

     printf("\nAs a character, variable c1 is %c", c1);
     printf("\nAs a number, variable c1 is %d", c1);

     /* Do the same for variable c2 */

     printf("\nAs a character, variable c2 is %c", c2);
     printf("\nAs a number, variable c2 is %d\n", c2);

     return 0;
}
