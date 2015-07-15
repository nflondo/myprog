/* print_it.c--This program prints a listing with line numbers! */
#include <stdlib.h>
#include <stdio.h>

void do_heading(char *filename);

int line, page;

int main( int argv, char *argc[] )
{
    char buffer[256];
    FILE *fp;

    if( argv < 2 )
    {
        printf("\nProper Usage is: " );
        printf("\n\nPRINT_IT filename.ext\n" );
        exit(1);
    }

    if (( fp = fopen( argc[1], "r" )) == NULL )
    {
        fprintf( stderr, "Error opening file, %s!", argc[1]);
        exit(1);
    }

    page = 0;
    line = 1;
    do_heading( argc[1]);

    while( fgets( buffer, 256, fp ) != NULL )
    {
        if( line % 55 == 0 )
            do_heading( argc[1] );

        printf("%4d:\t%s", line++, buffer );
    }

    printf("\f" );
    fclose(fp);
    return 0;
}

void do_heading( char *filename )
{
    page++;

    if ( page > 1)
        printf("\f" );

    printf("Page: %d, %s\n\n", page, filename );
}
