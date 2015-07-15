/* Copying a file. */

#include <stdio.h>

int file_copy( char *oldname, char *newname );

int main(void)
{
     char source[80], destination[80];

     /* Get the source and destination names. */

     printf("\nEnter source file: ");
     scanf("%80s",source);
     printf("\nEnter destination file: ");
     scanf("%80s",destination);

     if ( file_copy( source, destination ) == 0 )
         puts("Copy operation successful.\n");
     else
         fprintf(stderr, "Error during copy operation.\n");
     return 0;
}

int file_copy( char *oldname, char *newname )
{
     FILE *fold, *fnew;
     int c;

     /* Open the source file for reading in binary mode. */

     if ( ( fold = fopen( oldname, "rb" ) ) == NULL )
         return -1;

     /* Open the destination file for writing in binary mode. */

     if ( ( fnew = fopen( newname, "wb" ) ) == NULL  )
     {
         fclose ( fold );
         return -1;
     }

     /* Read one byte at a time from the source; if end of file */
     /* has not been reached, write the byte to the */
     /* destination. */

     while (1)
     {
         c = fgetc( fold );

         if ( !feof( fold ) )
             fputc( c, fnew );
         else
             break;
     }

     fclose ( fnew );
     fclose ( fold );

     return 0;
}
