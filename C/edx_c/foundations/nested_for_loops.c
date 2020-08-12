#include <stdio.h>

int main(void) {
    int numStars = 0;
    scanf("%d", &numStars);
    for (int i = 0; i < numStars; i++){
        for(int i = 0; i < numStars; i++){
            printf("*");   
        }
        printf("\n");
    }
return 0;
}