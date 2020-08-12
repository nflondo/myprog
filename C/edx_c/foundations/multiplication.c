#include <stdio.h>
int main() {
    int i;
    int result=0, userNumber=0;    
    
    //printf("Enter number for multiplication table: "); 
    scanf("%d", &userNumber);
    for(i=0; i<11; i++){
        result = (i * userNumber);
        printf("%dx%d = %d\n",i,userNumber, result);
    }
    
    return 0;
}