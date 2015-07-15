/* Illustrates variable scope. */

#include <stdio.h>

int print_value(void);

int value = 10;

int main(void)
{

   printf("Global var: %d\n", value);;
   print_value();
    return 0;
}

int print_value(void)
{
    int value = 2;
    printf("Local var: %d\n", value);
    return 0;
}
