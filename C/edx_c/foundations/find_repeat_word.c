
/* Find out how many letters occur multiple times in a word
*/
#include<stdio.h>
int main(void) {
    char myWord[51];
    int j = 0, wordSize, i, index, tmp, counter = 0;

    scanf("%s", myWord);

    while ( myWord[j] != '\0'){
        j++;
    }
    wordSize = j;
    // bubble sort letters in word alphabetically
    for (index = 0; index < wordSize -1; index++){
        for(i = 0; i < wordSize - 1; i++){
            if (myWord[i] > myWord[i + 1]){
                tmp = myWord[i];
                myWord[i] = myWord[i + 1];
                myWord[i + 1] = tmp;
            }
        }
    }

    //for (index = 0; index < wordSize -1; index++){
        for(i = 0; i < wordSize - 1; i++){
            if (myWord[i] == myWord[i + 1] && myWord[i] != myWord[i - 1]){
                counter++;
            }
    //    }
    }


    //for (i = 0; i < wordSize; i++){
    //    printf("%s\n", myWord);
        printf("%d", counter);
    //}

return 0;
}