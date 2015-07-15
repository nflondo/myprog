/* Demonstrates the relationship between addresses and */
/* elements of arrays of different data types. */

#include <stdio.h>

/* Declare three arrays and a counter variable. */

short s[10];
int i[10], x;
float f[10];
double d[10];

int main(void)
{
     /* Print the table heading */

     printf("%19s %10s %10s %10s", "Short", "Integer", 
	         "Float", "Double");

     printf("\n================================");
     printf("======================");

     /* Print the addresses of each array element. */

     for (x = 0; x < 10; x++)
	 printf("\nElement %d: %lu  %lu  %lu  %lu", x, 
	      (unsigned long)&s[x], (unsigned long)&i[x],
		  (unsigned long)&f[x], (unsigned long)&d[x]);

     printf("\n================================");
     printf("======================\n");

     return 0;
}
