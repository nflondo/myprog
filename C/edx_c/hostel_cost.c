#include <stdio.h>

int main(void) {
    int customerAge =0, luggageWeight = 0;
    int priceNight = 0;

    scanf("%d", &customerAge);
    scanf("%d", &luggageWeight);

    if ( customerAge == 60){
        priceNight = 0;
    } else if (customerAge < 10){
        priceNight = 5;
    } else if (luggageWeight > 20){
        priceNight = 30 + 10;        
    } else {
        priceNight = 30;
    }
    printf("%d", priceNight);    

    return 0;
}