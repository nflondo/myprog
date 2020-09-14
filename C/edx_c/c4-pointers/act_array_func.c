#include <stdio.h>

void behind(int *, int);

int main(void) {
    int array[10];
    int N, i;
    
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }
    behind(array, N);
    for (i=0; i<N; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}

/* Write your function behind() here: */
void behind(int * array, int size){
    int highest_score = array[0];
    for(int i = 0; i<size; i++){
        if(array[i] > highest_score){
            highest_score = array[i];
        }        
    }
    //printf("highest_score: %d\n", highest_score);
    for(int i = 0; i< size; i++){
        array[i] = highest_score - array[i];
    }
}