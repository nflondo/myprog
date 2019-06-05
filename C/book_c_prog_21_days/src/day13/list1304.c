/* Demonstrates the fgets() function. */

#include <stdio.h>

#define MAXLEN 10

int main(void)
{
    char buffer[MAXLEN];

    puts("Enter text a line at a time; enter a blank to exit.");

    while (1)
    {
         fgets(buffer, MAXLEN, stdin);

         if (buffer[0] == '\n')
            break;

         puts(buffer);
    }
    return 0;
}
