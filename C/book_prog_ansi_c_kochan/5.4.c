#include <stdio.h>

main()
{
    int idx, factorial,num;
    printf (" Number    Factorial\n");
    factorial=1;
    for (num=1 ; num <11; ++num){
        factorial = factorial * num ;
        printf ("%i     %i\n", num, factorial);
        
    
    }
}    
