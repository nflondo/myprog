 /* Demonstrates the # operator in macro expansion. */

#include <stdio.h>

#define OUT(x) printf(#x " is equal to %d.\n", x)

int  main(void)
{
    int value = 123;
    OUT(value);
    return 0;
}
