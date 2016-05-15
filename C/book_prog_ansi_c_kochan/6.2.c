#include <stdio.h>

main()
{
    int num1, num2, even_test;
    
    printf ("Enter two integers: ");
    scanf ("%i %i", &num1, &num2);
    
    even_test = num1 % num2 ;
    if ( even_test == 0 )
        printf ("Num: %i is evenly divisible by %i\n", num1, num2);
    else
        printf ("Num: %i is NOT evenly divisible by %i\n", num1, num2);

}
