/**
 * Your program should first read an integer number indicating how many tracking 
 * codes you plan on entering. Next, for each successive tracking code your program 
 * should read in the integer length of code followed by a space and then the type 
 * of code ('i' for integer, 'd' for decimal, or 'c' for character). Finally your 
 * program should print the total amount of space required to store all of the 
 * tracking codes (in bytes). If the user enters an incorrect type for any tracking 
 * number, the program should print 'Invalid tracking code type' and exit.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numCodes, numInput, totalBytes=0;    
    char codeType[1];

    scanf("%d", &numCodes);
    
    for(int i = 0; i < numCodes; i++){
        scanf("%d %c", &numInput, codeType);
        if (codeType[0] == 'i' ){
            //printf("%c", codeType[0]);
            totalBytes += (sizeof(int) * numInput);
            //printf("%d", totalBytes);
        } else if (codeType[0] == 'c')
        {
            totalBytes += (sizeof(char) * numInput);
            //printf("%d", totalBytes);
            
        } else if (codeType[0] == 'd')
        {
            totalBytes += (sizeof(double) * numInput);
            //printf("%d", totalBytes);
        } else
        {    
            printf("Invalid tracking code type");
            exit(1);
        }
    }
    printf("%d bytes", totalBytes);

return 0;
}