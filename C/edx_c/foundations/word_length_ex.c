#include <stdio.h>
int main(void) {
    //! showArray(word, cursors=[t])
    //! showArray(length, cursors=[i])
    int i = 0;
    int t = 0;
    int l = 0;
    int j = 0;
    int nbWords = 0;
    char word[11];
    // This integer array keeps track of the number of words in a letter
    int length[10];//length[5] number of 5-letter-long words in the text
    for(i=0;i<10;i++){
        length[i]=0;
    }
    scanf("%d", &nbWords);
    for(t=0;t<nbWords;t++){
        scanf("%s", word);
        l = 0;
        while(word[l]!='\0'){
            l++;
        }
        length[l] = length[l] + 1; // array starts to get populated on the correct index
        // every index correspond to the number of characters in a word and the 
        // content in the index is the number of words with that length
        printf("%s %d ", word,l);
    }
    // iterate over the array, each index is the word length and the content/value
    // of the index is the number of words with what length
    for(j=0;j<10;j++){
        printf("There are %d words with %d letters.\n", length[j], j);
    }
    return 0;   
}