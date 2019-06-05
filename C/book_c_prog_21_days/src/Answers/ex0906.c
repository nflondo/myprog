/* Exercise 9.6 */

#include <stdio.h>
#include <string.h>

/* function prototypes */
char * compare_strings( char *, char *);

int main(void)
{
    char *a = "Hello";
    char *b = "World!";
    char *longer;
       
    longer = compare_strings(a, b);

    printf( "The longer string is: %s\n", longer );
    
    return 0;
}

char * compare_strings( char * first, char * second)
{
    int x, y;

    x = strlen(first);
    y = strlen(second);

    if( x > y)
       return first;
    else
       return second;
}
