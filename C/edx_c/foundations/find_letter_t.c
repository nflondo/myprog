/* You are conducting a linguistic study and are interested in finding words 
that contain the letter 't' or 'T' in the first half of the word (including 
the middle letter if there is one). Specifically, if the first half of the 
word does contain a 't' or a 'T', your program should output a 1. If the first 
half does not contain the letter 't' or 'T', but the second half does, then 
your program should output a 2. Otherwise, if there is no 't' or 'T' in the word at all, your program's output should be -1. You may assume that the word entered does not have more than 50 letters.
*/
#include <stdio.h>
int main(void) {
    char myWord[51];
    int n = 50, wordLength = 0;
    int i, found = 0;

    scanf("%s", myWord);

    // Find word length
    i = 0;
    while ( myWord[i] != '\0'){
        i++;
    }
    wordLength = i;
    printf("%d\n", wordLength);  

    i = 0;
    while ( !found && myWord[i] != '\0'){
        if ( myWord[i] == 't'  || myWord[i] == 'T'){
            if (i <= wordLength / 2){
                found = 1;
            } else
            {
                found = 2;
            }      
            break;
        } else
        {
            i++;
        }        
    }

    if ( !found ){
        printf("-1");
    } else
    {
        printf("%d", found);
    }    

return 0;
}