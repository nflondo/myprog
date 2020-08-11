#include <stdio.h>

int main(void) {
    int numCities = 0, result = 0, cityPopulation = 0;
    int i;
    scanf("%d", &numCities);
    //int cityPopulation[numCities];
    for( i = 0; i < numCities; i++){
        scanf("%d", &cityPopulation);
        if (cityPopulation > 10000){
            result += 1;
        }
    }
    printf("%d", result);
}