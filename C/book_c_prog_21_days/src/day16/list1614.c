/* Using character test macros to create an integer */
/* input function. */
#include <stdio.h>
#include <ctype.h>

int get_int(void);

int main(void)
{
    int x;
    printf ("Enter an integer: ") ;
    x =  get_int();
    printf("You entered %d.\n\n", x);
    return 0;
}

int get_int(void)
{
    int ch, i, sign = 1;

    /* Skip over any leading white space. */

    while ( isspace(ch = getchar()) )
        ;

    /* If the first character is non-numeric, unget */
    /* the character and return 0. */

    if (ch != '-' && ch != '+' && !isdigit(ch) && ch != EOF)
    {
        ungetc(ch, stdin);
        return 0;
    }

    /* If the first character is a minus sign, set */
    /* sign accordingly. */

    if (ch == '-')
        sign = -1;

    /* If the first character was a plus or minus sign, */
    /* get the next character. */

    if (ch == '+' || ch == '-')
        ch = getchar();

    /* Read characters until a non-digit is input. Assign */
    /* values, multiplied by proper power of 10, to i. */

    for (i = 0; isdigit(ch); ch = getchar() )
        i = 10 * i + (ch - '0');

    /* Make result negative if sign is negative. */

    i *= sign;

    /* If EOF was not encountered, a nondigit character */
    /* must have been read in, so unget it. */

    if (ch != EOF)
        ungetc(ch, stdin);

    /* Return the input value. */

    return i;
}
