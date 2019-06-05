/* Demonstrates the getchar() function. */

#include <stdio.h>

int main(void)
{
   int ch;

   while ((ch = getchar()) != '\n')
        putchar(ch);

   return 0;
}
