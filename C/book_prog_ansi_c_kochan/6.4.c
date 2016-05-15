#include <stdio.h>

main()
{
    int num1;
    char operator;
    float accumulator;
    //operator=NULL;
    accumulator=0;
    while ( operator != 'E')
    {
        printf ("Enter Number and Operator: ");
        scanf ("%i %c", &num1, &operator);
        
        
        switch ( operator )
        {
            case '+':
            accumulator = accumulator + num1;
            printf ("Accum: %.4f\n", accumulator);
                break;        
            case '-':
            accumulator = accumulator - num1;
            printf ("Accum: %.4f\n", accumulator);
                break;
            case '*':
            accumulator = accumulator * num1;
            printf ("Accum: %.4f\n", accumulator);
                break;

            case '/':
            if (num1 == 0)
                printf ("Division by 0\n");
            else 
            {
                accumulator = accumulator / num1;
                printf ("Accum: %.4f\n", accumulator);
            }
                    break;
            case 'S':
            accumulator = num1;
            printf ("Accum: %.4f\n", accumulator);
                break;
            case 'E':  
                break;
            default:
                printf ("Invalid Operator\n");
                break;
         } // switch
      } // while
}     
