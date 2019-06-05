/* Demonstration using printf() to display numerical values. */

#include <stdio.h>

int a = 2, b = 10, c = 50;
float f = (float) 1.05, g = (float) 25.5, h = (float) -0.1;

int main(void)
{
    printf("\nDecimal values without tabs: %d %d %d", a, b, c);
    printf("\nDecimal values with tabs: \t%d \t%d \t%d", a, b, c);

    printf("\nThree floats on 1 line: \t%f\t%f\t%f", f, g, h);
    printf("\nThree floats on 3 lines: \n\t%f\n\t%f\n\t%f", f, g, h);

    printf("\nThe rate is %f%%", f);
    printf("\nThe result of %f/%f = %f\n", g, f, g / f);
      
    return 0;
}
