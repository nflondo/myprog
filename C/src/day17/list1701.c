/* Demonstrates some of C's math functions */

#include <stdio.h>
#include <math.h>

int main(void)
{

    double x;

    printf("Enter a number: ");
    scanf( "%lf", &x);

    printf("\nOriginal value: %f\n", x);

    printf("Ceil: %f\n", ceil(x));
    printf("Floor: %f\n", floor(x));
    if( x >= 0 )
        printf("Square root: %f\n", sqrt(x) );
    else
       printf("Negative number\n" );

    printf("Cosine: %f\n", cos(x));
    return 0;
}
