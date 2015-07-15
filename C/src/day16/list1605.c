/* The strcat() function. */

#include <stdio.h>
#include <string.h>

char str1[27] = "a";
char str2[2];

int main(void)
{
     int n;

     /* Put a null character at the end of str2[]. */

     str2[1] = '\0';

     for (n = 98; n < 123; n++)
     {
         str2[0] = n;
         strcat(str1, str2);
         puts(str1);
     }
     return 0;
}
