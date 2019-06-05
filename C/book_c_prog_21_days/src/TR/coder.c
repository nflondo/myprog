/* Program:  Coder.c
 * Usage:    Coder  [filename] [action]
 *              where filename = filename for/with coded data
 *              where action = D for decode anything else for
 *                            coding
 *--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encode_character( int ch, int val );
int decode_character( int ch, int val );

int main( int argc, char *argv[])
{
    FILE *fh;               /* file handle  */
    int rv = 1;             /* return value */
    int ch = 0;             /* variable to hold a character */
    unsigned int ctr = 0;   /* counter */
    int val = 5;            /* value to code with */
    char buffer[256];       /* buffer */

    if( argc != 3 )
    {
       printf("\nError:  Wrong number of parameters..." );
       printf("\n\nUsage:\n   %s filename action", argv[0]);
       printf("\n\n   Where:");
       printf("\n        filename = name of file to code or decode");
       printf("\n        action   = D for decode or C for encode\n\n");
       rv = -1;       /* set return error value */
    }
    else
    if(( argv[2][0] == 'D') || (argv [2][0] == 'd' ))  /* to decode */
    {
        fh = fopen(argv[1], "r");   /* open the file   */
        if( fh <= 0 )               /* check for error */
        {
            printf( "\n\nError opening file..." );
            rv = -2;               /* set return error value */
        }
        else
        {
            ch = getc( fh );     /* get a character */
            while( !feof( fh ) )  /* check for end of file */
            {
               ch = decode_character( ch, val );
               putchar(ch);  /* write the character to screen */
               ch = getc( fh);
            }

            fclose(fh);
            printf( "\n\nFile decoded to screen.\n" );
        }
    }
    else  /* assume coding to file. */
    {

        fh = fopen(argv[1], "w");
        if( fh <= 0 )
        {
            printf( "\n\nError creating file..." );
            rv = -3;  /* set return value */
        }
        else
        {
            printf("\n\nEnter text to be coded. ");
            printf("Enter a blank line to end.\n\n");

            while( fgets(buffer, 256, stdin) != NULL )
            {
                if( strlen (buffer) <= 1 )
                     break;

                for( ctr = 0; ctr < strlen(buffer); ctr++ )
                {
                    ch = encode_character( buffer[ctr], val );
                    ch = fputc(ch, fh);    /* write the character to file */
                }
            }
            printf( "\n\nFile encoded to file.\n" );
            fclose(fh);
        }

    }
    return rv;
}

int encode_character( int ch, int val )
{
    ch = ch + val;
    return ch;
}

int decode_character( int ch, int val )
{
    ch = ch - val;
    return ch;
}
