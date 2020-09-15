#include <stdio.h>
int main(void){
    //! showMemory(cursors=[words[0], words[1], words[2]], start=65520)
    char words[3][10]; // enter 3 strings with 9 letters max
    int i;
    printf("Please enter three words: ");
    for (i=0; i<3; i++) {
        scanf("%s", words[i]); // assign to array of strings
    }
    printf("You entered: \n");
    for (i=0; i<3; i++) {
        printf("%s ", words[i]);
    }
    printf("\nFirst letters: \n");
    for (i=0; i<3; i++) {
        // words[1][0] give specific letter from each string array 
        printf("\"%s\" starts with the letter '%c'.\n", words[i], words[i][0]);
    }
    return 0;
}