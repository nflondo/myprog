/* mortgage.c - Calculates loan/mortgage payments. */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    float principal, rate, payment;
    int term;
    char ch;

    while (1)
    {
       /* Get loan data */
        puts("\nEnter the loan amount: ");
        scanf("%f", &principal);
        puts("\nEnter the annual interest rate: ");
        scanf("%f", &rate);
        /* Adjust for percent. */
        rate /= 100;
        /* Adjust for monthly interest rate. */
        rate /= 12;

        puts("\nEnter the loan duration in months: ");
        scanf("%d", &term);
        payment = (principal * rate) / (1 - pow((1 + rate), -term));
        printf("Your monthly payment will be $%.2f.\n", payment);

        puts("Do another (y or n)?");
        do
        {
        ch = getchar();
        } while (ch != 'n' && ch != 'y');

        if (ch == 'n')
            break;
    }
    return 0;
}
