#include <stdio.h>

int main(void) {
    int numCars = 0;
    double carWeight = 0, avgWeight = 0;
    double totalWeight = 0, weightArray[50];

    scanf("%d", &numCars);
    for(int i = 0; i < numCars; i++){
        scanf("%lf", &carWeight);
        weightArray[i] = carWeight;
    }
    // calculate ideal weight per car
    for(int i = 0; i < numCars; i++){
        totalWeight += weightArray[i];
    }
    //printf("totalWeight:%lf\n", totalWeight);
    avgWeight = totalWeight / (double)numCars;
    //printf("avgWeight:%lf\n", avgWeight);
    for(int i = 0; i < numCars; i++){

        if(weightArray[i] > avgWeight)          
            printf("-%.1lf\n", weightArray[i] - avgWeight);
        else
        {
            printf("%.1lf\n", avgWeight - weightArray[i] );
        }        
    }    

return 0;
}