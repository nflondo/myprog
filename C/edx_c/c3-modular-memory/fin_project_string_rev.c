#include <stdio.h>

int isReverse(char firstArray[], char secondArray[]);

int main() {
    int result;
    char firstWord[100], secondWord[100];
    scanf("%s %s", firstWord, secondWord);

    result = isReverse(firstWord, secondWord);
    
    if (result){
        printf("%s is the reverse of %s", firstWord, secondWord);
    } else{
        printf("%s is not the reverse of %s", firstWord, secondWord);
    }
    //printf("You entered: %s, %s\n", firstWord, secondWord);    
}

int isReverse (char firstArray[], char secondArray[]){
    /*
    int firstArraySize=0;
    while(firstArray[firstArraySize] != '\0')
        firstArraySize++;

    firstArraySize = firstArraySize -1;
    */
    int secondArraySize=0;
    while(secondArray[secondArraySize] != '\0')
        secondArraySize++;

    secondArraySize = secondArraySize -1;

    //printf("firstArraySize %d\n", firstArraySize);
    int i=0, k = secondArraySize; 

    while(firstArray[i] != '\0' || k >= 0){
        printf("firstArray[i]: %c\n", firstArray[i]);
        printf("secondArray[k]: %c\n", secondArray[k]);
        if (firstArray[i] == secondArray[k]){
            i++;
            k--;        
        }
        else
        {
            //break;
            return 0;
        }        
    }
    return 1;
}