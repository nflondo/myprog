#include <stdio.h>

int main() {
    char letter1 = ' ';
    char letter2 = '+';
    //char letter3 = 'C';
    int piramid_height = 5, horizontal_count = 4, symbol_entered = 1;

    printf("Enter character: ");
    scanf("%c", &letter1);
    
    for(int i =0; i < piramid_height; i++){
        for(int i =0; i < horizontal_count; i++){
            printf("%c", letter2);
        }
        for(int i = 0; i < symbol_entered; i++){    
            printf("%c", letter1);            
        }
        for(int i =0; i < horizontal_count; i++){
            printf("%c", letter2);
        }
        horizontal_count -= 1;
        symbol_entered += 2;
        printf("\n");
    }
    
return 0;
}