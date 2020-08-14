#include <stdio.h>

int main(void) {
    int numWords, wordLength[11];
    char words[11];
    int wordIndex = 0, lengthIndex = 0, longest = 0;

    // Initialize int array to all zeros to avoid weird values
    for(int i = 0; i < 11; i++){
        wordLength[i] = 0;
    }

    scanf("%d", &numWords); // Read number of words first from user
    /* Reads one word at a time.  User can type one word then [return], then next
    * word and so on or user can type all the words in one line separated by spaces
    */
    for(int i = 0; i < numWords; i++){
        scanf("%s", words);

        wordIndex = 0;
        while(words[wordIndex] != '\0'){  // count letters in the word
            wordIndex++;
        }
        wordLength[lengthIndex] = wordIndex; // populate array with length of each word
        lengthIndex++;
        //printf("%s %d\n", words, wordIndex);
    }
    // Find biggest number in the array of wordLength
    for(int i = 0; i < 11; i++){    
        //printf("Index: %d Word Length: %d\n", i, wordLength[i]);
        if ( wordLength[i] > longest){
            longest = wordLength[i];
        }    
    }
    printf("%d", longest);

    return 0;
}