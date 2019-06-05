/* Demonstrates puts(). */

#include <stdio.h>

/* Declare and initialize an array of pointers. */

char *messages[5] = { "This", "is", "a", "short", "message." };

int main(void)
{
     int x;

     for (x=0; x<5; x++)
         puts(messages[x]);

     puts("And this is the end!");
     
     return 0;
}

