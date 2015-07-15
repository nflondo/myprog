/* Demonstrates pointers and multidimensional arrays. */

#include <stdio.h>

int multi[2][4];

int main(void)
{
    printf("multi = %lu\n", (unsigned long)multi);
    printf("multi[0] = %lu\n", (unsigned long)multi[0]);
    printf("&multi[0][0] = %lu\n", 
	                  (unsigned long)&multi[0][0]);
    return 0;
}
