#include <stdio.h>

int main(void) {
    int ingredients[10], userIndex;
    
    //for(int index=0; index < 10; index++){
        scanf("%d %d %d %d %d %d %d %d %d %d", &ingredients[0], &ingredients[1],
         &ingredients[2], &ingredients[3], &ingredients[4], &ingredients[5], 
         &ingredients[6], &ingredients[7], &ingredients[8], &ingredients[9]);
    //}
    scanf("%d", &userIndex);
    printf("%d", ingredients[userIndex]);

return 0;
}