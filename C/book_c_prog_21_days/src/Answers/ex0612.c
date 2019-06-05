#include <stdio.h>

#define  MAX  100

int main(void)
{
    int array [MAX];
    int count = -1, maximum, minimum, num_entered, temp;
    
    puts("Enter integer values one per line.");
    puts("Enter 0 when finished.");
    
    do
    {
        scanf("%d", &temp);
        array[++count] = temp;
    } while (count < (MAX-1) && temp != 0);
    
    num_entered = count;
    
    /* Find the largest and smallest values.      */
    /* At the start, the first value is both the  */
    /* maximum and the minimum.                   */
    maximum = minimum = array [0];
    
    for(count = 1; count < num_entered; count++)
    {
        if (array[count] > maximum)
            maximum = array[count];
        if (array[count] < minimum)
            minimum = array[count];
        
    }

    printf("The maximum value is %d.\n", maximum);
    printf("The minimum value is %d.\n", minimum);

    return 0;
}

