/* Demonstrates strcpy(). */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char source[] = "The source string.";

int main(void)
{
     char dest1[80];
     char *dest2, *dest3;

     printf("source: %s\n", source );

     /* Copy to dest1 is okay because dest1 points to */
     /* 80 bytes of allocated space. */

     strcpy(dest1, source);
     printf("dest1:  %s\n", dest1);

     /* To copy to dest2 you must allocate space. */

     dest2 = (char *)malloc(strlen(source) +1);
     strcpy(dest2, source);
     printf("dest2:  %s\n", dest2);

     /* Copying without allocating destination space is a no-no. */
     /* The following could cause serious problems. */

     /* strcpy(dest3, source); */
     return 0;
}
