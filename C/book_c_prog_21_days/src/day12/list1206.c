/* Demonstrates the switch statement correctly. */

#include <stdio.h>

int main(void)
{
   int reply;

   puts("\nEnter a number between 1 and 5:");
   scanf("%d", &reply);

   switch (reply)
   {
     case 0:
	 break;
     case 1:
	{
	  puts("You entered 1.\n");
	  break;
	}
     case 2:
	{
	  puts("You entered 2.\n");
	  break;
	}
     case 3:
	{
	  puts("You entered 3.\n");
	  break;
	}
     case 4:
	{
	  puts("You entered 4.\n");
	 break;
	}
     case 5:
	{
	  puts("You entered 5.\n");
	  break;
	}
    default:
	{
	  puts("Out of range, try again.\n");
	}
   }              /* End of switch */
   return 0;
}
