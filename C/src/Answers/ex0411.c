#include <stdio.h>

int three_powered (int power);

int main (void)
{
    int a = 4, b = 19;
    
    printf("3 to the power of %d is %d\n", a, three_powered(a));
    printf("3 to the power of %d is %d\n", b, three_powered(b));
    
    return 0;
}

int three_powered (int power)
{
    if (power < 1)
        return 1;
    else
        return 3 * three_powered (power -1);
}
