/* Searching with strstr(). */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *loc, buf1[80], buf2[80];

    /* Input the strings. */

    printf("Enter the string to be searched: ");
    fgets(buf1,80,stdin);
    printf("Enter the target string: ");
    fgets(buf2,80,stdin);
    buf2[strlen(buf2)-1] = 0;  /* Strip the newline char. */

    /* Perform the search. */
    loc = strstr(buf1, buf2);

    if ( loc ==  NULL )
        printf("No match was found.\n");
    else
        printf("%s was found at position %d.\n", buf2, loc-buf1);
    return 0;
}
