/* Using the function tolower() */
#include <stdio.h>
#include <ctype.h>

char* strlwr(char *str);

int main(void)
{
    char buffer[80];

    printf("Enter a string to convert: ");
    fgets(buffer,80,stdin);

    strlwr (buffer);

    printf (buffer);

    return 0;
}

char* strlwr(char *str)
{
    int k ;

    for (k = 0 ; str [k] ; k++)
        str[k] = tolower(str[k]);

    return str ;
}
