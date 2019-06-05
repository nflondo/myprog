/* Demonstrates ftell() and rewind(). */
#include <stdlib.h>
#include <stdio.h>

#define BUFLEN 6

char msg[] = "abcdefghijklmnopqrstuvwxyz";

int main(void)
{
     FILE *fp;
     char buf[BUFLEN];

     if ( (fp = fopen("text.txt", "w")) == NULL)
     {
         fprintf(stderr, "Error opening file.\n");
         exit(1);
     }

     if (fputs(msg, fp) == EOF)
     {
         fprintf(stderr, "Error writing to file.\n");
         exit(1);
     }

     fclose(fp);

     /* Now open the file for reading. */

     if ( (fp = fopen("text.txt", "r")) == NULL)
     {
         fprintf(stderr, "Error opening file.\n");
         exit(1);
     }
     printf("Immediately after opening, position = %ld\n", ftell(fp));

     /* Read in 5 characters. */

     fgets(buf, BUFLEN, fp);
     printf("After reading in %s, position = %ld\n", buf, ftell(fp));

     /* Read in the next 5 characters. */

     fgets(buf, BUFLEN, fp);
     printf("The next 5 characters are %s, and position now = %ld\n",
             buf, ftell(fp));

     /* Rewind the stream. */

     rewind(fp);

     printf("After rewinding, the position is back at %ld\n",
             ftell(fp));

     /* Read in 5 characters. */

     fgets(buf, BUFLEN, fp);
     printf("and reading starts at the beginning again: %s\n", buf);
     fclose(fp);
     return 0;
}
