#include <stdio.h>

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
