#include <stdio.h>

float average (float a, float b, float c, float d, float e);

int main(void)
{
	float result, v, w, x, y, z;
	
	puts( "Enter 5 float numbers: ");
	scanf ( "%f%f%f%f%f", &v, &w, &x, &y, &z );
	
	result = average(v, w, x, y, z);
	printf( "\n\nAverage = %f\n", result );
	
	return 0;

}

float average (float a, float b, float c, float d, float e){
 float avg;
 
 avg = ((a + b + c + d + e)/5);
 
 return avg;

}


