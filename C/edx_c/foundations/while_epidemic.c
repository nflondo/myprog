#include <stdio.h>
int main(){
    int totalPopulation;
    int totalInfections = 1, day = 1;
    scanf("%d", &totalPopulation);

    while ( totalInfections < totalPopulation){
        day++;
        totalInfections += totalInfections * 2;
    }
    printf("%d", day);

return 0;
}