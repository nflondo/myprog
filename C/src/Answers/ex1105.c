/* Exercise 11.5 */
#include <stdio.h>

void print_value (void);

int var = 99;

int main(void)
{
    int var = 77;
    printf ("Printing in function with local and global.\n");
    printf("The value of var is %d.\n", var);
    print_value();
    
    return 0;
}

void print_value (void)
{
    printf ("Printing in function with only global.\n");
    printf("The value is %d.\n", var);
}

