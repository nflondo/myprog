/* list_it.c__This program displays a listing with line numbers! */
#include <stdio.h>
#include <stdlib.h>
  
void display_usage(void);
int line;

int main( int argc, char *argv[] )
{
    char buffer[256];
    FILE *fp;

    if( argc < 2 )
    {
       display_usage();
       return 1;
    }

    if (( fp = fopen( argv[1], "r" )) == NULL )
    {
         fprintf( stderr, "Error opening file, %s!\n", argv[1] );
         return 1;
    }

    line = 1;

    while( fgets( buffer, 256, fp ) != NULL )
       fprintf( stdout, "%4d:\t%s", line++, buffer );

    fclose(fp);
    return 0;
}

void display_usage(void)
{
       fprintf(stderr, "\nProper Usage is: " );
       fprintf(stderr, "\n\nlist_it filename.ext\n" );
}
