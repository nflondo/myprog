#include <stdio.h>

main()
{
    int number;
    int right_digit;
//    char minus_sign = 0;
    
    printf ("Enter your number: ");
    scanf ("%i", &number);
    
    
    do
    {
        right_digit = number % 10;
        //printf ("%i", right_digit);
        switch ( right_digit )
        {
            case 0:
                printf (" zero ");
            break; 
            case 1:
                printf (" one ");
            break; 
            case 2:
                printf (" two ");
            break; 
            case 3:
                printf (" three ");
            break; 
            case 4:
                printf (" four ");
            break; 
            case 5:
                printf (" five ");
            break; 
            case 6:
                printf (" six ");
            break; 
            case 7:
                printf (" seven ");
            break;
            case 8:
                printf (" eight ");
            break; 
            case 9:
                printf (" nine ");
            break;  
            
        }
        number = number / 10;
    }
    while ( number != 0 );
    printf ("\n");
}    
