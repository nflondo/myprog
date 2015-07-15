#include <stdio.h>

int radius, area;

int main(void)
{
	printf( "Enter radius: ");
	scanf ( "%d", &radius );
	area = (int) (3.14159 * radius * radius);
	printf( "\n\nArea = %d\n", area );
	return 0;

}


