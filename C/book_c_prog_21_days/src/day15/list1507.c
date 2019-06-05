/* Detecting end-of-file. */
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 100

int main(void)
{
    char buf[BUFSIZE];
    char filename[60];
    FILE *fp;

    puts("Enter name of text file to display: ");
    fgets(filename,60,stdin);
    filename[strlen(filename)-1] = 0;
  
    /* Open the file for reading. */
    if ( (fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file.\n\n");
        exit(1);
    }

    /* If end of file not reached, read a line and display it. */

    while ( !feof(fp) )
    {
        fgets(buf, BUFSIZE, fp);
        printf("%s",buf);
    }
    printf ("\n");
    fclose(fp);
    return 0;
}
