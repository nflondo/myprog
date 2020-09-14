/* An array of pointers can make an array of arrays.
*/
#include <stdio.h>
int main(void){
     //! showMemory(cursors=[a, arrays[0], b, arrays[1], c, arrays[2]], start=65520)
    // Declare three arrays of shorts
    short a[3] = {234,655, 843};
    short b[2] = {12, 62};
    short c[4] = {3456, 3467, 23, 276};

    // Declare an array of pointers (which is an array of arrays)
    short * arrays[3] = {a, b, c};
    
    // De-reference position 0 and give it value of 5
    * arrays[0] = 5;
    // Same as line above, but using square brackets
    arrays[0][0] = 0;
    // De-reference second element in first array and give it value of 6
    * (arrays[0] + 1) = 6;
    // Same as line above, but using square brackets
    arrays[0][1] = 0;

    * (arrays[0] + 2) = 7;
    arrays[0][2] = 0;

    * arrays[1] = 3;
    arrays[1][0] = 0;

    * (arrays[1] + 1) = 4;
    arrays[1][1] = 0;

    * arrays[2] = 99;
    * (arrays[2] + 1) = 100;
    * (arrays[2] + 2) = 101;
    * (arrays[2] + 3) = 102;
    
    arrays[2][0] = 0;
    arrays[2][1] = 0;
    arrays[2][2] = 0;

    return 0;
}