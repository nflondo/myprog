#include <stdio.h>

int main() {
    int amount = 0, sum = 0, numberRead = 0;
    printf("How many items to sum?: ");
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++){
        scanf("%d", &numberRead);
        printf("I've read %d from input terminal\n", numberRead);
        sum += numberRead;
        printf("Sum equals: %d\n", sum);
    }
return 0;
}
