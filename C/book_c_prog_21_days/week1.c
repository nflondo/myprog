/* Program Name: week1.c                                     */
/*               program to enter the ages and incomes of up */
/*               to 100 people.  The program prints a report */
/*               based on the numbers entered.               */
/*-----------------------------------------------------------*/
/*--------------------*/ 
/* included files     */
/*--------------------*/
#include <stdio.h>

/*--------------------*/
/* defined constants  */
/*--------------------*/

#define MAX   100
#define YES   1
#define NO    0

/*--------------------*/
/* variables          */
/*--------------------*/

long    income[MAX]; /* to hold incomes     */
int     month[MAX], day[MAX], year[MAX]; /* to hold birthdays */
int     ctr;   /* For counting        */

/*--------------------*/
/* function prototypes*/
/*--------------------*/

int display_instructions(void);
void get_data(void);
void display_report(void);
int continue_function(void);

/*--------------------*/
/* start of program   */
/*--------------------*/

int main(void)
{
    int cont; /* For program control */
    
    cont = display_instructions();

    if ( cont == YES )
    {
        get_data();
        display_report();
    }
    else
        printf( "\nProgram Aborted by User!\n\n");
            
    return 0;
}
/*-------------------------------------------------------------*
 *  Function:  display_instructions()                          *
 *  Purpose:   This function displays information on how to    *
 *             use this program and asks the user to enter 0   *
 *             to quit, or 1 to continue.                      *
 *  Returns:   NO  - if the user enters 0                      *
 *             YES - if the user enters any number other than 0*
 *-------------------------------------------------------------*/

int display_instructions( void )
{
    int cont;
    
    printf("\n\n");
    printf("\nThis program enables you to enter up to 99 people\'s ");
    printf("\nincomes and birthdays.  It then prints the incomes by");
    printf("\nmonth along with the overall income and overall average.");
    printf("\n");

    cont = continue_function();

    return cont;
}
/*-------------------------------------------------------------*
 *  Function:  get_data()                                      *
 *  Purpose: This function gets the data from the user. It     *
 *           continues to get data until either 100 people are *
 *           entered, or until the user enters 0 for the month.*
 *  Returns: nothing                                           *
 *  Notes:   This allows 0/0/0 to be entered for birthdays in  *
 *           case the user is unsure.  It also allows for 31   *
 *           days in each month.                               *
 *-------------------------------------------------------------*/

void get_data(void)
{
    int cont;
    
    for ( cont = YES, ctr = 0; ctr < MAX && cont == YES; ctr++ )
    {
        printf("\nEnter information for Person %d.", ctr+1 );
        printf("\n\tEnter Birthday:");

        do
        {
            printf("\n\tMonth (0 - 12): ");
            scanf("%d", &month[ctr]);
        } while (month[ctr] < 0 || month[ctr] > 12 );

        do
        {
            printf("\n\tDay (0 - 31): ");
            scanf("%d", &day[ctr]);
        } while ( day[ctr] <  0 || day[ctr] > 31 );

        do
        {
            printf("\n\tYear (0 - 1997): ");
            scanf("%d", &year[ctr]);
        } while ( year[ctr] < 0 || year[ctr] > 1997 );

        printf("\nEnter Yearly Income (whole dollars): ");
        scanf("%ld", &income[ctr]);

        cont = continue_function();
    }
    /* ctr equals the number of people that were entered.    */
    
    return;
}
/*----------------------------------------------------------*
 *  Function: display_report()                              *
 *  Purpose:  This function displays a report to the screen *
 *  Returns:  nothing                                       *
 *  Notes:    More information could be printed.            *
 *----------------------------------------------------------*/

void display_report()
{
    int    x, y;   /* For couning */
    int    month_total, grand_total;  /* For totals      */


    grand_total = 0;
    printf("\n\n\n");                   /* skip a few lines   */
    printf("\n        SALARY SUMMARY");
    printf("\n        ==============");

    for( x = 0; x <= 12; x++ )  /* for each month, including 0*/
    {
        month_total = 0;
        for( y = 0; y < ctr; y++ )
        {
            if( month[y] == x )
                month_total += income[y];
        }
        printf("\nTotal for month %d is %d", x, month_total);
        grand_total += month_total;
    }
    printf("\n\nReport totals:");
    printf("\nTotal Income is %d", grand_total);
    printf("\nAverage Income is %d", grand_total/ctr );

    printf("\n\n* * * End of Report * * *\n");
}
/*----------------------------------------------------------------*
 * Function: continue_function()                                  *
 * Purpose:  This function asks the user if they wish to continue.*
 * Returns:  YES - if user wishes to continue                     *
 *           NO - if user wishes to quit                          *
 *----------------------------------------------------------------*/

int continue_function( void )
{
    int x;
    
    printf("\n\nDo you wish to continue? (0=NO/1=YES): ");
    scanf( "%d", &x );

    while( x < 0 || x > 1 )
    {
        printf("\n%d is invalid!", x);
        printf("\nPlease enter 0 to Quit or 1 to Continue: ");
        scanf("%d", &x);
    }
    if(x == 0)
        return NO;
    else
        return YES;
}

