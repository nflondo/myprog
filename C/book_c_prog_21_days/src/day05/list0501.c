/* Demonstrates a simple for statement */

#include <stdio.h>

int count;

int main(void)
{
    /* Print the numbers 1 through 20 */

    for (count = 1; count <= 20; count++)
        printf("\n%d", count);
    
    return 0;
}
