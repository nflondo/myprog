/* > 1000 = fire; 100 - 1000 = zone to watch
dynamically allocate the memory for the number of zones it is to handle(use 
functions provided)
The inputs of the program are first the length, then the width of an area, 
then the average temperatures of all zones, row by row.
The output should pinpoint the possible zones with fires with [X] and the watch
zone with a [*], the other zone are displayed with [ ].
*/
#include <stdio.h>
#include <stdlib.h>

int ** allocateIntStarArray(int num);
int * allocateIntArray(int num);
void printMatrix(int ** arr, int w, int l);

int main(void){
    int length, width;
    //int * row;

    scanf("%d %d\n", &length, &width);
    
    int ** col = allocateIntStarArray(width);
    for(int i = 0; i < width; i++){
        int * row = allocateIntArray(length);
        for(int j = 0; j < length; j++)
            scanf("%d", &row[j]);
        col[i] = row;    
    }
/*
    scanf("%d", &row[1]);
    
    int * row2 = allocateIntArray(length);
    scanf("%d", &row2[0]);
    scanf("%d", &row2[1]);
    
    int * row3 = allocateIntArray(length);
    scanf("%d", &row3[0]);
    scanf("%d", &row3[1]);
    
    
    col[0] = row;
    col[1] = row2;
    col[2] = row3;
*/
/*
    printf("%d", *col[0]);
    printf("%d\n", col[0][1]);
    printf("%d", *col[1]);
    printf("%d\n", col[1][1]);
    printf("%d", *col[2]);
    printf("%d\n", col[2][1]);
*/
printMatrix(col, width, length); 
    
    /*
    for(int i = 0; i < width; i++){
        for(int j=0; j < length; j++){
            print("%ds", *col[width][length]);
        }
    }
    */
}  // end main
void printMatrix(int ** arr, int w, int l){
    
    for(int i = 0; i < w; i++){
        for(int j = 0; j < l; j++){
            //printf("%d", arr[i][j]);
            if (arr[i][j] > 1000)
                printf("[X]");
            else if (arr[i][j] > 99 && arr[i][j] < 1001)
            {
                printf("[*]");                
            }
            else
            {
                printf("[ ]");
            }        
        }
        printf("\n");
    }
}  
/*used to allocate an array of pointers, each of which will store a pointer to a 
row of integers (temperatures of zones). That is, the function returns a pointer
 to an array of pointers. Each cell of this array will point to an array of 
 integers containing the temperature values for the zones.
*/
int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}

/*  used to allocate the space required to store the average temperatures in one
 row of zones, that is, an array of integers. The function therefore returns a 
 pointer to such an array of integers. 
*/
int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}