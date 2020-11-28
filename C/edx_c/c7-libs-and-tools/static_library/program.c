#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 5.3, 9.8, 1.8, 0.3};
	double result=averageTemp(temperatures, 7);
	printf("Avg tmp: %lf", result);
	return 0;
}
