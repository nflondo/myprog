#include <stdio.h>

float average (float a, float b, float c, float d, float e);

int main (void)
{
    float v, w, x, y, z, answer;
	
    puts("Enter 5 numbers:");
	scanf("%f%f%f%f%f", &v, &w, &x, &y, &z);

	answer = average(v, w, x, y, z);
	
	printf("The average is %f\n", answer);
	
	return 0;
}

float average (float a, float b, float c, float d, float e)
{
    return ((a+b+c+d+e)/5);
}
