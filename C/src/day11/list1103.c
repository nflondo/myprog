/* Illustrates declaring external variables. */

#include <stdio.h>

int x = 999;

void print_value(void);

int main(void)
{
    extern int x;

    printf("%d\n", x);
    print_value();

    return 0;
}

void print_value(void)
{
    extern int x;
    printf("%d\n", x);
}

