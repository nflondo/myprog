/* 1 meter = 3.2808 feet;
1 gram = 0.002205 pounds;
temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.
*/
#include <stdio.h>

double metersToFeet( double metricNum );

int main(void) {
    int numConversions;
    double metricInput;
    char metricUnit;
    scanf("%d", &numConversions);

    scanf("%lf %c", &metricInput, &metricUnit );
    if(metricUnit == 'm'){
        double feet;
        feet = metersToFeet( metricInput);
        printf("%6lf ft", feet);
    }

//    printf("You entered: %d %c\n", metricInput, metricUnit);
return 0;
}

double metersToFeet( double metricNum ){
    double result;

    result = metricNum * 3.2808;
    return result;
}