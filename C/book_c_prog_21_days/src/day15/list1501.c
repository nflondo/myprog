 /* Demonstrates the fopen() function. */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch, filename[40], mode[5];

    while (1)
    {

        /* Input filename and mode. */

        printf("\nEnter a filename: ");
        fgets(filename,40,stdin);
        filename [strlen(filename)-1] = 0 ;
        printf("\nEnter a mode (max 3 characters): ");
        fgets(mode,5,stdin);
        mode [strlen(mode)-1] = 0 ;

        /* Try to open the file. */

        if ( (fp = fopen( filename, mode )) != NULL )
        {
            printf("\nSuccessful opening %s in mode %s.\n",
                    filename, mode);
            fclose(fp);
            puts("Enter x to exit, any other to continue.");
            if ( (ch = getc(stdin)) == 'x')
                break;
            else
                continue;
        }
        else
        {
            fprintf(stderr, "\nError opening file %s in mode %s.\n",
                    filename, mode);
            perror("list1501");
            puts("Enter x to exit, any other to try again.");
            if ( (ch = getc(stdin)) == 'x')
                break;
            else
                continue;
        }
    }
    return 0 ;
}
