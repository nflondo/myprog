/* The strcmp() function. */
 
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    int x;

    while (1)
    {
        /* Input two strings. */

        printf("\n\nInput the first string, a blank to exit: ");
        fgets(str1,80,stdin);
        str1[strlen(str1)-1] = 0;

        if ( strlen(str1) < 2 )
            break;

        printf("\nInput the second string: ");
        fgets(str2,80,stdin);
        str2[strlen(str2)-1] = 0;

        /* Compare them and display the result. */

        x = strcasecmp(str1, str2);

        printf("\nstrcmp(%s,%s) returns %d", str1, str2, x);
    }
    return 0;
}
