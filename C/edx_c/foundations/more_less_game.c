#include <stdio.h>
int main() {
    int numberToGuess = 1, playerGuess = 0, numTries=0;
    scanf("%d", &numberToGuess);

    //scanf("%d", &playerGuess);
    while( playerGuess != numberToGuess ){
        scanf("%d", &playerGuess);       
        numTries++;        
        if(playerGuess < numberToGuess){
            printf("it is more\n");
        } else if (playerGuess > numberToGuess) {
            printf("it is less\n");
        } else {
            /* code */
        }    
    }
    printf("Number of tries needed:\n%d", numTries);

return 0;
}