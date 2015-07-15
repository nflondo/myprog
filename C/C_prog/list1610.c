/* Searching with strcspn(). */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char  buf1[80], buf2[80];
    char *loc;

    /* Input the strings. */

    printf("Enter the string to be searched: ");
    fgets(buf1,80,stdin);
    printf("Enter the string containing target characters: ");
    fgets(buf2,80,stdin);
    buf2[strlen(buf2)-1] = 0; /* Strip the newline char. */

    /* Perform the search. */

    loc = strpbrk(buf1, buf2);

    if ( loc ==  NULL )
        printf("No match was found.\n");
    else
        printf("The first match was found at position %d.\n", (int)(loc-buf1));
    return 0;
}
