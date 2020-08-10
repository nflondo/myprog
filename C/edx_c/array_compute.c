#include <stdio.h>
int main(void) {
    //! showArray(ages, cursors=[i])
    int ages[10];
    int i;
    int ageMax = 0;
    for (i=0; i<10; i++) {
        scanf("%d", &ages[i]);
        if (ages[i] > ageMax) {
            ageMax = ages[i];
        }
    }
    printf("The maximum age is %d.\n", ageMax);
    printf("Age differences with the eldest person:\n");
    for(i=0;i<10;i++){
        printf("%d:%d ", ages[i],ageMax-ages[i]);
    }
    return 0;
}