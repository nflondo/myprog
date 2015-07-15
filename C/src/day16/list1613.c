/* Demonstration of atof(). */
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     char buf[80];
     double d;

     while (1)
     {
         printf("\nEnter the string to convert (blank to exit): ");
         fgets(buf,80,stdin);

         if ( strlen(buf) < 2 )
             break;

         d = atof( buf );

         printf("The converted value is %f.\n", d);
     }
     return 0;
}
