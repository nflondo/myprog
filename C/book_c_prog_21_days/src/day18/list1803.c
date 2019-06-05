/* Using realloc() to change memory allocation. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buf[80], *message;

    /* Input a string. */

    puts("Enter a line of text.");
    fgets(buf,80,stdin);
    buf[strlen(buf)-1] = 0;  /* Strip off newline char. */

    /* Allocate the initial block and copy the string to it. */
    message = realloc(NULL, strlen(buf)+1);
    strcpy(message, buf);

    /* Display the message. */

    puts(message);

    /* Get another string from the user. */

    puts("Enter another line of text.");
    fgets(buf,80,stdin);
    buf[strlen(buf)-1] = 0;  /* Strip off newline char. */

    /* Increase the allocation, then concatenate the string to it. */
	
    message = realloc(message, (strlen(message)+strlen(buf)+1));
    strcat(message, buf);

    /* Display the new message. */
    puts(message);
    return 0;
}

