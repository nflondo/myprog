/* Demonstrating the shift operators. */

#include <stdio.h>

int main(void)
{
    unsigned char y, x = 255;
    int count;

    printf("%s %15s %13s\n", "Decimal", "shift left by", "result");

    for (count = 1; count < 8; count++)
    {
         y = x << count;
         printf("%6d %12d %16d\n", x, count, y);
    }
    printf("%s %16s %13s\n", "Decimal", "shift right by", "result");

    for (count = 1; count < 8; count++)
    {
         y = x >> count;
         printf("%6d %12d %16d\n", x, count, y);
    }
    return 0;
}
