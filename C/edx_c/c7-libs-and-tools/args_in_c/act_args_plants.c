//Activity: pass numbers to a program from the command line
#include <stdio.h>
#include <stdlib.h> // for atoi and atof (ascii to integer)
#include <string.h> // for strcmp

int main(int argc, char *argv[]){
    int numPlants;
    double pricePlant, totalPrice;

    if (argc != 3){
        printf("Invalid input.");
        return 0;
    }
    numPlants = atoi(argv[1]);  
    pricePlant = atof(argv[2]);  
    totalPrice = pricePlant * numPlants;
    printf("%d plants for %.2lf dollars each cost %.2lf dollars",numPlants, pricePlant, totalPrice);

}