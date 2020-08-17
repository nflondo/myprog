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
            found = 1;
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