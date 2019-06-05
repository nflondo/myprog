/* Searching with strspn(). */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char  buf1[80], buf2[80];
    size_t loc;

    /* Input the strings. */

    printf("Enter the string to be searched: ");
    fgets(buf1,80,stdin);
    printf("Enter the string containing target characters: ");
    fgets(buf2,80,stdin);
	buf2[strlen(buf2)-1] = 0;  /* Strip the newline char. */

    /* Perform the search. */
    loc = strspn(buf1, buf2);

    if ( loc ==  0 )
        printf("No match was found.\n");
    else
        printf("Characters match up to position %d.\n", loc-1);

    return 0;
}
