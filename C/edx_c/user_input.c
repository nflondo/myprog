#include <stdio.h>
int main(){
    int first, second, third;
    printf("Please enter three integers, separated by commas: ");
    scanf("%d, %d, %d", &first, &second, &third);
    printf("You entered: %d for first, %d for second, %d for third\n", first, second, third);
    return 0;    
}
