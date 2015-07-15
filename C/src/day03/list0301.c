/* Demonstrates unary operator prefix and postfix modes */

#include <stdio.h>

int a, b;

int main(void)
{
     /* Set a and b both equal to 5 */

     a = b = 5;

     /* Print them, decrementing each time. */
     /* Use prefix mode for b, postfix mode for a */

     printf("\nPost  Pre");
     printf("\n%d     %d", a--, --b);
     printf("\n%d     %d", a--, --b);
     printf("\n%d     %d", a--, --b);
     printf("\n%d     %d", a--, --b);
     printf("\n%d     %d\n", a--, --b);

     return 0;
}

