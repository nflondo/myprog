#include <stdio.h>
/* Calculate avg of floating point values     */

main()
{

	float sum = 0;
	float average = 0;
	int index;
	float numbers[10] = { 5.5, 6.5, 7.5, 8.5, 9.5, 10, 5, 6.5, 8.5, 9 };

	for ( index =0; index < 11; ++index)
		sum = sum + numbers[index];

	printf ("Average = %f\n", sum / 10);
}
