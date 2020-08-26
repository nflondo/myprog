/* write a fun
*/
#include <stdio.h>
int min( int x, int y);

int main(void) {
    int numElements;

    scanf("%d", &numElements);
    int numList[numElements + 1];
    int listValue, currentMin, smallestNum;

    for(int i = 0; i < numElements; i++){
        scanf("%d", &listValue);
        numList[i] = listValue;
        currentMin = min(numList[i], numList[i - 1]);
        if(i == 0){
            smallestNum = currentMin;
        } else if ( currentMin < smallestNum )
        {
            smallestNum = currentMin;
        }
        
    }

    printf("%d\n", smallestNum);

}

int min( int x, int y){
    
    if ( x < y){
        return x;
    } else 
    {
        return y;
    }    
}