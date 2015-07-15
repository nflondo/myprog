/* Inputs two floating point numbers and   */
/* displays their product.                 */
#include <stdio.h>

int main(void)
{
	float x, y;
	
	puts("Enter two values: ");
	scanf("%f %f", &x, &y);
	printf("The product of %f and %f is %f.\n", x, y, x*y);
    return 0;
}

