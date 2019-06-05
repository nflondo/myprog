/* Illustrates variable scope. */

#include <stdio.h>

int print_value(x);

int main(void)
{
   int x;
   x = 999;

    printf("%d\n", x);
    print_value(x);

    return 0;
}

int print_value(x)
{
    printf("%d\n", x);
}

