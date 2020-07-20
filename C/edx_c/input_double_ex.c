#include <stdio.h>
int main(void) {
    double kilometers = 0, result = 0;
    double rate=0.621371;
    //printf("How tall are you (in meters)? ");
    scanf("%lf", &kilometers);
    // convert kil to miles
    result = kilometers * rate;
    //scanf("%lf", &height);
    printf("%.6lf kilometers is equal to %.6lf miles.", kilometers, result);
    return 0;
}