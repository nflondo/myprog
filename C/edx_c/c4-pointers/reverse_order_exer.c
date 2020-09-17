// Print text in reverse order
#include <stdio.h>
int main(void){
    char words[69][40];
    int i;
    //printf("Please enter three words: ");
    for (i=0; i < 68; i++) {
        scanf("%s", words[i]); // assign to array of strings
    }
    //    printf("You entered: \n");
    // Reverse words entered
    for (i=67; i >= 0; i--) {
        printf("%s ", words[i]);
    }

}