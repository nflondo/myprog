/* Demonstrates the sizeof() operator */
#include <stdio.h>

/* Declare several 100 element arrays */

int intarray[100];
long longarray[100];
float floatarray[100];
double doublearray[100];

int main(void)
{
    /* Display the sizes of numeric data types */

    printf("\nSize of short = %d bytes", (int) sizeof(short));
    printf("\nSize of int = %d bytes", (int) sizeof(int));
    printf("\nSize of long = %d bytes", (int) sizeof(long));
    printf("\nSize of float = %d bytes", (int) sizeof(float));
    printf("\nSize of double = %d bytes", (int) sizeof(double));

    /* Display the sizes of the three arrays */

    printf("\nSize of intarray = %d bytes", (int) sizeof(intarray));
    printf("\nSize of longarray = %d bytes", (int) sizeof(longarray));
    printf("\nSize of floatarray = %d bytes",
           (int) sizeof(floatarray));
    printf("\nSize of doublearray = %d bytes\n",
           (int) sizeof(doublearray));

    return 0;
}
