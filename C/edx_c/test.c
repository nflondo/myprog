#include <stdio.h>
<<<<<<< HEAD
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
=======

int main(void){ 
    char character1, character2; 
    scanf("%c%c", &character1, &character2); 
    printf("++++%c++++\n", character1); 
    printf("+++%c%c%c+++\n", character1, character1, character1); 
    printf("++%c%c%c%c%c++\n", character1, character1, character1, character1, character1); 
    printf("+%c%c%c%c%c%c%c+\n", character1, character1, character1, character1, character1, character1, character1); 
    printf("%c%c%c%c%c%c%c%c%c\n", character1, character1, character1, character1, character1, character1, character1, character1, character1);

printf("++++%c++++\n", character2);
printf("+++%c%c%c+++\n", character2, character2, character2);
printf("++%c%c%c%c%c++\n", character2, character2, character2, character2, character2);

printf("+%c%c%c%c%c%c%c+\n", character2, character2, character2, character2, character2, character2, character2); 
printf("%c%c%c%c%c%c%c%c%c\n", character2, character2, character2, character2, character2, character2, character2, character2, character2); 
return 0; 

}
>>>>>>> fe0fb2a09738bd435e5c21a6cba892bf54ae64cf
