#include <stdio.h>

main()
{
    int num1, num2;
    float div_test;
    printf ("Enter two integers: ");
    scanf ("%i %i", &num1, &num2);
    
    if ( num2 == 0 )
        printf ("Division by 0 not pemitted\n");
    else
    {
        div_test = (float)num1 / num2;
        printf ("Result of division: %.3f\n", div_test);
    }
}
