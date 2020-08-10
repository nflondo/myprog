#include <stdio.h>

int main(void) {
    int numIngredients = 0;
    double ingredientsCost = 0, totalCost = 0;
    //double pricePerPound = 0.0, ingredientWeight = 0.0;
    int i;
    scanf("%d", &numIngredients);
    double pricePerPound[numIngredients], weightNeeded[numIngredients];
    for(i = 0; i < numIngredients; i++){
        scanf("%lf", &pricePerPound[i]);        
    }
    for(i = 0; i < numIngredients; i++){
        scanf("%lf", &weightNeeded[i]);
    }

    // Total cost = 
    for(i = 0; i < numIngredients; i++){
        ingredientsCost += pricePerPound[i] * weightNeeded [i];
    }

    printf("%.6lf", ingredientsCost);

    return 0;
}