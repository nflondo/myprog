/* Demonstrates using an infinite loop and the switch */
/* statement to implement a menu system. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu(void);

int main(void)
{

   while (1)
   {
	 /* Get user's selection and branch based on the input. */

	 switch(menu())
	 {
	    case 1:
		{
                  puts("\nExecuting task A.");
		  sleep(1);
		  break;
		}
	    case 2:
		{
                  puts("\nExecuting task B.");
		  sleep(1);
		  break;
		}
	    case 3:
		{
                  puts("\nExecuting task C.");
		  sleep(1);
		  break;
		}
	    case 4:
		{
                  puts("\nExecuting task D.");
		  sleep(1);
		  break;
		}
	    case 5:     /* Exit program. */
		{
		  puts("\nExiting program now...\n");
		  sleep(1);
		  exit(0);
		}
	    default:
		{
		  puts("\nInvalid choice, try again.");
		  sleep(1);
		}
	 }  /* End of switch */
    }       /* End of while  */
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
