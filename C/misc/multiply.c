#include <stdio.h>

/* calculate product of two numbers */

int a,b,c;

int product(int x, int y);

int main(void)
{
	printf("Enter number 1: ");
	scanf("%d", &a);

	printf("Enter number 2: ");
	scanf("%d", &b);
	
	/*calculate and display product */
	c = product(a,b);
	printf("%d times %d = %d\n", a, b, c);
	
	return 0;
}

int product(int x, int y)
{
	return (x * y);

}
