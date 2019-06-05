/* Exercise 11.2 */

#include <stdio.h>

void print_value (int x);

int main(void)
{
    int x = 999;
    
    printf("%d\n", x);
    print_value(x);
    
    return 0;
}

void print_value (int x)
{
    printf("%d\n", x);
}

