#include <stdio.h>
/* Program to generate a table of primer numbers (numbers
only divided by themselves and 1                */

main()
{
    int numbers[150], i, j;
    for (i = 0; i < 150; ++i)
        numbers[i]= 0;

    for (i = 2; i <= 150; ++i){
        if ( numbers[i]== 0)
        {
            printf ("%i", numbers[i]);
            break;
        }    
        for ( j =2; j < i ; ++j ) // only test odd divisors
            if ( (i * j) < 150 )
                numbers[i * j] = 1;
     }
     
     for (i=0; i < 150; ++i)
        printf("Index: %i %i\n",i, numbers[i]);
     /*
     int p, is_prime, d;
    
    printf ("2 ");  // we start off knowing 2 is prime
    for ( p = 3; p <= 50; p = p + 2 )  // now start testing odd numbers from 3
    {
        is_prime =1;
        
        for ( d =3; d < p && is_prime; d = d + 2 ) // only test odd divisors
            if ( p % d == 0 )
                is_prime = 0;
                
        if ( is_prime != 0)
            printf ("%i ", p);
    }    
    printf ("\n");
     */       
}
