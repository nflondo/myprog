#include <stdio.h>
// Reverse digits of a number
main()
{
    int number;
    int right_digit;
    char minus_sign = 0;
    
    printf ("Enter your number.\n");
    scanf ("%i", &number);
    if ( number < 0)
    {
        number = -number;  // gives me absolute value
        minus_sign = 1;
    }
    do
    {
        right_digit = number % 10;
        printf ("%i", right_digit);
        number = number / 10;
    }
    while ( number != 0 );
    if ( minus_sign )
        printf ("-");
    
    printf ("\n");
}
