/* Exercise 9.5 */

#include <stdio.h>

#define SIZE 10

/* function prototypes */
void copyarrays( int [], int []);

int main(void)
{
    int ctr=0;
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[SIZE];

    /* values before copy */
    for (ctr = 0; ctr < SIZE; ctr ++ )
    {
       printf( "a[%d] = %d, b[%d] = %d\n", 
               ctr, a[ctr], ctr, b[ctr]);
    }
    
    copyarrays(a, b);

    /* values after copy */   
    for (ctr = 0; ctr < SIZE; ctr ++ )
    {
       printf( "a[%d] = %d, b[%d] = %d\n", 
               ctr, a[ctr], ctr, b[ctr]);
    }

    return 0;
}

void copyarrays( int orig[], int newone[])
{
    int ctr = 0;

    for (ctr = 0; ctr < SIZE; ctr ++ )
    {
        newone[ctr] = orig[ctr];
    }
}
