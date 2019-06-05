/* Can be used to demonstrate redirection of stdin and stdout. */

#include <stdio.h>

int main(void)
{
   char buf[80];

   fgets(buf,80,stdin);
   printf("The input was: %s\n", buf);
   return 0;
}
