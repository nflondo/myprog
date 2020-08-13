#include <stdio.h>
int main() {
    int minTemp, maxTemp;
    int currentTemp = 0;
    scanf("%d %d", &minTemp, &maxTemp);

    while ( currentTemp != -999){
        scanf("%d", &currentTemp);
        if( currentTemp <= maxTemp  && currentTemp >= minTemp){
            printf("Nothing to report\n");
        } else if ( currentTemp == -999){
            break;
        } else {
            printf("Alert!\n");
            break;
        }
    }
}