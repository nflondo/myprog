/* Demonstrates the equivalence of stream input and output. */
#include <stdio.h>

int main(void)
{
    char buffer[256];

    /* Input a line, then immediately output it. */

    puts(fgets(buffer,256,stdin));
 
    return 0;
}
