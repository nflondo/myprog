#include <stdio.h>

void print_letter2(void);

int main(void)
{
   char letter1 = 'X';
   int  ctr;
   
   for( ctr = 0; ctr < 10 ; ctr++ )
   {
       printf("%c", letter1);
       print_letter2();
   } 
   puts ("");
   return 0;
}

void print_letter2(void)
{
   char letter2 = '=';
   int  ctr;        /* This variable is local */
                    /* it is different from the one in main() */
   
   for( ctr = 0; ctr < 2 ; ctr++ )
       printf("%c", letter2);
}
