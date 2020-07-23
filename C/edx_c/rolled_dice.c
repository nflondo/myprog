#include <stdio.h>
int main(){
    int numThrows = 0;
    int red = 0, yellow = 0, green = 0, ones = 0, tens = 0, hundreds = 0, sum = 0;
    double average = 0.0;
    
    scanf("%d", &numThrows);
    for(int i = 1; i <= numThrows; i++){
        scanf("%d %d %d", &red, &yellow, &green);
        ones = red;
        tens = (yellow * 10) + ones;
        hundreds = (green * 100) + tens;
        sum += hundreds;
        average = (double)sum/i;
        printf("%d. you rolled: %d, current average: %.1lf\n", i, hundreds, average);
    }
   
    return 0;
}