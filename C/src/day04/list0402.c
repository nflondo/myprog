/* Illustrates the difference between arguments and parameters. */

#include <stdio.h>

float x = (float) 3.5, y = (float) 65.11, z;

float half_of(float k);

int main(void)
{
    /* In this call, x is the argument to half_of(). */
    z = half_of(x);
    printf("The value of z = %f\n", z);

    /* In this call, y is the argument to half_of(). */
    z = half_of(y);
    printf("The value of z = %f\n", z);
   
    return 0;
}

float half_of(float k)
{
    /* k is the parameter. Each time half_of() is called, */
    /* k has the value that was passed as an argument. */

    return (k/2);
}
