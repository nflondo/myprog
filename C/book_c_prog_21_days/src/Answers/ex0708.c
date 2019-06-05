#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short random [1000];
    int a;
    int total = 0;
    
    for(a = 0 ; a < 1000; a++)
    {
         random [a] = rand();
         total += random [a];
    }
    
    printf("Average is %d\n", total / 1000);
        
    /* Now display the elements 10 at a time. */
    for(a = 0 ; a < 1000; a++)
    {
        printf("random [%4d] = %d\n", a, random [a]);
        
        if (a % 10 == 0 && a > 0)
        {
            printf("Press enter to continue, CTRL-C to quit.\n");
            getchar();
        }
    }

    return 0;
}
