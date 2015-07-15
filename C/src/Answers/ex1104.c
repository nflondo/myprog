/* Exercise 11.4 */
#include <stdio.h>

void print_value (int x);

int main(void)
{
    int var = 99;
    
    print_value(var);
    
    return 0;
}

void print_value (int x)
{
    printf("The value is %d.\n", x);
}

