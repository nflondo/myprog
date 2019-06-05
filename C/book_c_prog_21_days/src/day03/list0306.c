#include <stdio.h>

/* Initialize variables. Note that c is not less than d, */
/* which is one of the conditions to test for. */
/* Therefore the entire expression should evaluate as false.*/

int a = 5, b = 6, c = 5, d = 1;
int x;

int main(void)
{
     /* Evaluate the expression without parentheses */

     x = a < b || a < c && c < d;
     printf("\nWithout parentheses the expression evaluates to %d.", x);

     /* Evaluate the expression with parentheses */

     x = (a < b || a < c) && c < d;
     printf("\nWith parentheses the expression evaluates to %d.\n", x);
     return 0;
}
