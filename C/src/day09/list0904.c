/* Demonstrates using the fgets() library function. */

#include <stdio.h>

/* Allocate a character array to hold input. */

char input[40];

int main(void)
{
     puts("Enter some text, then press Enter: ");
     fgets(input,40,stdin);
     printf("You entered: %s\n", input);

     return 0;
}
