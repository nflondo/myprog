/* Exercise 11.3 */

#include <stdio.h>

void print_value (void);

int var = 99;

int main(void)
{
    print_value();
    
    return 0;
}

void print_value (void)
{
    printf("The value is %d.\n", var);
}

