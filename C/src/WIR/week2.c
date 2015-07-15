/*-------------------------------------------------*/
/* Program Name:  week2.c                          */
/* program to enter information for up to 100      */
/* people.  The program prints a report            */
/*          based on the numbers entered.          */
/*-------------------------------------------------*/
/*---------------------*/
/* included files      */
/*---------------------*/
#include <stdio.h>
#include <stdlib.h>

/*---------------------*/
/* defined constants   */
/*---------------------*/
#define MAX   100
#define YES   1
#define NO    0

#define FNAME_LEN  20
#define LNAME_LEN  24
#define PHONE_LEN  10

/*---------------------*/
/* variables           */
/*---------------------*/

struct record 
{
    char fname[FNAME_LEN];         /* first name + NULL   */
    char lname[LNAME_LEN];         /* last name + NULL    */
    char phone[PHONE_LEN];         /* phone number + NULL */
    int  income;                   /* incomes             */
    int  month;                    /* birthday month      */
    int  day;                      /* birthday day        */
    int  year;                     /* birthday year       */
};

struct record list[MAX];      /* declare actual structure */

int last_entry = 0;           /* total number of entries  */

/*---------------------*/
/* function prototypes */
/*---------------------*/
void get_data(void);
void display_report(void);
int  continue_function(void);
void clear_kb(void);
void new_gets(char*str, int len);

/*---------------------*/
/* start of program    */
/*---------------------*/

int main(void)
{
    int cont = YES;
    int ch;

    while( cont == YES )
    {
        printf( "\n");
        printf( "\n     MENU");
        printf( "\n   ========\n");
        printf( "\n1.  Enter names");
        printf( "\n2.  Print report");
        printf( "\n3.  Quit");
        printf( "\n\nEnter Selection ==> ");

        ch = getchar();
       
        clear_kb() ; /* remove extra characters from keyboard buffer */

        switch( ch )
        {
            case '1': get_data();
                      break;
            case '2': display_report();
                      break;
            case '3': printf("\n\nThank you for using this program!\n");
                      cont = NO;
                      break;
            default:  printf("\n\nInvalid choice, Please select 1 to 3!");
                      break;
        }
     }

    return 0;
}

/*-----------------------------------------------------------*
 *  Function:  get_data()                                    *
 *  Purpose: This function gets the data from the user. It   *
 *         continues to get data until either 100 people are *
 *         entered, or the user chooses not to continue.     *
 *  Returns: nothing                                         *
 *  Notes: This allows 0/0/0 to be entered for birthdates in *
 *      case the user is unsure.  It also allows for 31 days *
 *       in each month.                                      *
 *-----------------------------------------------------------*/

void get_data(void)
{
    int cont;

    for ( cont = YES; last_entry < MAX && cont == YES;last_entry++ )
    {
        printf("\n\nEnter information for Person %d.",last_entry+1 );

        printf("\n\nEnter first name: ");
        new_gets(list[last_entry].fname, FNAME_LEN);

        printf("\nEnter last name: ");
        new_gets(list[last_entry].lname, LNAME_LEN);

        printf("\nEnter phone in 123-4567 format: ");
        new_gets(list[last_entry].phone, PHONE_LEN);

        printf("\nEnter Yearly Income (whole dollars): ");
        scanf("%d", &list[last_entry].income);

        printf("\nEnter Birthday:");
 
        do
        {
            printf("\n\tMonth (0 - 12): ");
            scanf("%d", &list[last_entry].month);
        } while ( list[last_entry].month < 0 ||
              list[last_entry].month > 12 );

       do
       {
           printf("\n\tDay (0 - 31): ");
           scanf("%d", &list[last_entry].day);
       } while ( list[last_entry].day <  0 ||
              list[last_entry].day > 31 );

       do
       {
           printf("\n\tYear (1800 - 1996): ");
           scanf("%d", &list[last_entry].year);
       } while (list[last_entry].year != 0 &&
            (list[last_entry].year < 1800 ||
             list[last_entry].year > 1996 ));

       cont = continue_function();
    }

    if( last_entry == MAX)
        printf("\n\nMaximum Number of Names has been entered!\n");
}

/*-----------------------------------------------------------*
 *  Function:  display_report()                              *
 *  Purpose:   This function displays a report to the screen *
 *  Returns:   nothing                                       *
 *  Notes:     More information could be displayed.          *
 *             Change stdout to stdprn to Print report       *
 *-----------------------------------------------------------*/

void display_report()
{
    int    month_total = 0,
           grand_total = 0;       /* For totals */
    int    x, y;

    printf("\n\n");      /* skip a few lines */
    printf("\n           REPORT");
    printf("\n          ========");

    for( x = 0; x <= 12; x++ )   /* for each month, including 0 */
    {
        month_total = 0;
        for( y = 0; y < last_entry; y++ )
        {
            if( list[y].month == x )
            {
                printf("\n\t%s %s %s %d",list[y].fname,
                      list[y].lname, list[y].phone,list[y].income);
                month_total += list[y].income;
            }
        }
        printf("\nTotal for month %d is %d",x,month_total);
        grand_total += month_total;
    }
    printf("\n\nReport totals:");
    printf("\nTotal Income is %d", grand_total);
    printf("\nAverage Income is %d", grand_total/last_entry );

    printf("\n\n* * * End of Report * * *");
}

/*-------------------------------------------------------------------*
 *  Function:  continue_function()                                   *
 *  Purpose:   This function asks the user if they wish to continue. *
 *  Returns:   YES - if user wishes to continue                      *
 *             NO  - if user wishes to quit                          *
 *-------------------------------------------------------------------*/

int continue_function( void )
{
    int ch;

    printf("\n\nDo you wish to continue? (Y)es/(N)o: ");

    clear_kb();
    ch = getchar();

    while( ch != 'n' && ch != 'N' && ch != 'y' && ch != 'Y' )
    { 
        printf("\n%c is invalid!", ch);
        printf("\n\nPlease enter \'N\' to Quit or \'Y\' to Continue: ");

        fflush(stdin);     /* clear keyboard buffer (stdin) */
        ch = getchar();
    }
   
    clear_kb();  /* this function is similar to fflush(stdin) */

    if(ch == 'n' || ch == 'N')
        return NO;
     else
        return YES;
}

/*--------------------------------------------------------------------*
 *  Function:  clear_kb()                                             *
 *  Purpose:   This function clears the keyboard of extra characters. *
 *  Returns:   Nothing                                                *
 *  Note:      This function could be replaced by fflush(stdin);      *
 *--------------------------------------------------------------------*/
void clear_kb(void)
{
    char junk[80];
    fgets(junk, 80, stdin);
}

/*--------------------------------------------------------------------*
 *  Function:  new_gets()                                             *
 *  Purpose:   This function gets a string from the keyboard using    *
 *             fgets() and removes the trailing newline charcater.    *
 *  Returns:   Nothing                                                *
 *--------------------------------------------------------------------*/
void new_gets(char*str, int len)
{
    int index;

    fgets(str, len, stdin);

    for(index = 0; index < len; index++)
        if (str[index] == '\n')
        {
            str[index] = 0;
            return;
        }
}
