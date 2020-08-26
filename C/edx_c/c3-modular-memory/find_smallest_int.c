/* The goal of this problem is to find the smallest integer in a list of numbers.

To help you with this task, please write a function called min() that finds and returns the smallest amongst two integers (be sure to also write a prototype for this function). The function thus takes two integers as input and returns the smallest of the two. This function will use an if statement with a condition that contains either "less than" or "greater than".

Next, please use min() in your main function to work your way through an entire list of numbers in order to find its minimum. The first number you read gives the number of elements in the list of integers under consideration. You will then read the integer values, using min() to keep only the smallest integer read at each step. In the end, please print out the smallest integer in the list.
*/
#include <stdio.h>
int min( int x, int y);

int main(void) {
    int numElements;

    scanf("%d", &numElements);
    int numList[numElements + 1];
    int listValue, currentMin, smallestNum;

    //Read first two elements outside of the loop
    scanf("%d %d", &numList[0], &numList[1]);
    smallestNum = min(numList[0], numList[1]);        

    for(int i = 2; i < numElements; i++){
        scanf("%d", &listValue);
        numList[i] = listValue;
        currentMin = min(numList[i], numList[i - 1]);
        if ( currentMin < smallestNum )
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