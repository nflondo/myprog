/* 1 meter = 3.2808 feet;
1 gram = 0.002205 pounds;
temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.
*/
#include <stdio.h>

double metersToFeet( double metricNum );
double gramsToPounds( double metricAmount);
double celciusToFarenheit ( double metricInput);

int main(void) {
    int numConversions;
    double metricInput;
    char metricUnit;
    scanf("%d", &numConversions);

    for(int i = 0 ; i < numConversions; i++){
        scanf("%lf %c", &metricInput, &metricUnit );
        if(metricUnit == 'm'){
            double feet;
            feet = metersToFeet( metricInput);
            printf("%6lf ft\n", feet);
        } else if (metricUnit == 'g')
        {
            double pounds;
            pounds = gramsToPounds( metricInput);
            printf("%6lf lbs\n", pounds);
        } else if (metricUnit == 'c'){
            double farenheit;
            farenheit = celciusToFarenheit( metricInput);
            printf("%6lf f\n", farenheit);
        }
    }

//    printf("You entered: %d %c\n", metricInput, metricUnit);
return 0;
}

double metersToFeet( double metricNum ){
    double result;

    result = metricNum * 3.2808;
    return result;
}

double gramsToPounds( double metricAmount){
    double result;
    result = metricAmount * 0.002205 ;
    return result;
}

double celciusToFarenheit ( double metricInput){
    double result;
    result = (metricInput * 1.8) + 32;
    return result;
}