/* Demonstrates using an infinite loop to implement */
/* a menu system. */
#include <stdio.h>
#define DELAY  1500000       /* Used in delay loop. */

int menu(void);
void delay(void);

int main(void)
{
   int choice;

   while (1)
   {

    /* Get the user's selection. */

    choice = menu();

    /* Branch based on the input. */

    if (choice == 1)
         {
             puts("\nExecuting task A.");
             delay();
         }
    else if (choice == 2)
	 {
             puts("\nExecuting task B.");
	     delay();
	 }
    else if (choice == 3)
	 {
             puts("\nExecuting task C.");
	     delay();
	 }
    else if (choice == 4)
	 {
             puts("\nExecuting task D.");
	     delay();
	 }
    else if (choice == 5)       /* Exit program. */
	 {
	     puts("\nExiting program now...\n");
	     delay();
	     break;
	 }
	 else
	 {
	     puts("\nInvalid choice, try again.");
	     delay();
	 }
   }
   return 0;
}

/* Displays a menu and inputs user's selection. */
int menu(void)
{
    int reply;

    puts("\nEnter 1 for task A.");
    puts("Enter 2 for task B.");
    puts("Enter 3 for task C.");
    puts("Enter 4 for task D.");
    puts("Enter 5 to exit program.");

    scanf("%d", &reply);

    return reply;
}

void delay( void )
{
    long x;
    for ( x = 0; x < DELAY; x++ )
	;
}
