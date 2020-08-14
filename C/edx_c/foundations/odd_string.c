#include <stdio.h>
int main() {
    char stuName[51];
    int i = 0;

    scanf("%s", stuName);
    while( stuName[i] != '\0'){
        i++;
    }
    if ( i % 2 == 0){
        printf("%d\n", 1);
    } else
    {
        printf("%d\n", 2);
    }    

return 0;
}