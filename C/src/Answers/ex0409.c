#include <stdio.h>

int product(int x, int y);
int divide_em(int a, int b);

int main (void)
{
    int number1 = 10,
        number2 = 5;
    int x, y, z;

    x = product(number1, number2);
    y = divide_em(number1, number2);
    z = divide_em(number1, 0);
 
    printf("number1 is %d and number2 is %d\n", number1, number2);
    printf("number1 * number2 is %d\n", x);
    printf("number1 / number2 is %d\n", y);
    printf("number1 / 0 is %d\n", z);

    return 0;
}

int product(int x, int y)
{
    return (x * y);
}

int divide_em(int a, int b)
{
    if (b == 0)
        return 0;
    return (a / b);
}
