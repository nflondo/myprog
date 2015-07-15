/* A program which can be run in the background. */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int count;

    for(count = 0; count < 10; count ++)
    {
        sleep(2);
        puts("I'm still running!");        
    }

    puts("I've finished now!");
    return 0;
}
 
