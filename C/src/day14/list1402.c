/* Demonstrates the sizes of multidimensional array elements. */

#include <stdio.h>

int multi[2][4];

int main(void)
{
     printf("The size of multi = %u\n", sizeof(multi));
     printf("The size of multi[0] = %u\n", sizeof(multi[0]));
     printf("The size of multi[0][0] = %u\n", sizeof(multi[0][0]));
     return 0;
}
