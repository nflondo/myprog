/* Demonstrates nested while statements */

#include <stdio.h>

int array[5];

int main(void)
{
   int ctr = 0,
       nbr = 0;

    printf("This program prompts you to enter 5 numbers\n");
    printf("Each number should be from 1 to 10\n");

    while ( ctr < 5 )
    {
        nbr = 0;
        while (nbr < 1 || nbr > 10)
        {
            printf("\nEnter number %d of 5: ", ctr + 1 );
            scanf("%d", &nbr );
        }

        array[ctr] = nbr;
        ctr++;
    }

    for (ctr = 0; ctr < 5; ctr++)
        printf("\nValue %d is %d", ctr + 1, array[ctr] );
      
    return 0;
}
