#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array [5][4];
	int a, b;
	
	for(a = 0 ; a < 5; a++)
	    for(b = 0; b < 4; b++)
		    array [a][b] = rand();
			
	/* Now print the array elements. */
	for(a = 0 ; a < 5; a++)
	{
	   for(b = 0; b < 4; b++)
		    printf ("%12d\t", array [a][b]);

		printf("\n"); /* Go to a new line */
	}

	return 0;
}
