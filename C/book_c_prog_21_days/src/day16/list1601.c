/* Using the strlen() function. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    size_t length;
    char buf[80];

    while (1)
    {
        puts("\nEnter a line of text, a blank line to exit.");
        fgets(buf,80,stdin);

        length = strlen(buf);

        if (length > 1)
            printf("That line is %u characters long.\n", length-1);
        else
            break;
    }
    return 0;
}
