#include <stdio.h>
/* Calculates sum of digits of an integer */
main()
{
    int number, right_digit, sum;
    printf ("Enter your number: ");
    scanf ("%i", &number);
    sum=0;
    //right_digit=0;
    do
    {
        right_digit = number % 10;
        //printf ("right_digit: %i\n", right_digit);
        sum = sum + right_digit;
        //printf ("sum: %i\n",sum);
        number = number / 10;
        //printf ("number: %i\n", number);
    }
    while ( number != 0 );
    printf ("Sum: %i\n", sum);
}
