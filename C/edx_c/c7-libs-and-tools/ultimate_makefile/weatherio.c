    #include <stdio.h>

    void printTemps(double *temps, int numOfTemps) {
    	int i;
    	printf("Over the past %d days, the temperatures were: \n", numOfTemps);
    	for (i=0; i<numOfTemps; i++) {
    		printf("%d: %.2lf\n", i+1, temps[i]);
    	}
    }


