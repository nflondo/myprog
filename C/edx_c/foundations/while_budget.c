#include <stdio.h>
int main(){
    int amount = 0, sum = 0;
    scanf("%d",&amount);
    while ( amount != -1){
        sum += amount;
        scanf("%d",&amount);        
    }
    printf("%d", sum);
return 0;
}