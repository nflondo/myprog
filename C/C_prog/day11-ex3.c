/* Illustrates variable scope. */

#include <stdio.h>

int print_value(void);

int var = 2;

int main(void)
{
   print_value();

    return 0;
}

int print_value(void)
{
    printf("%d\n", var);
    return 0;
}
