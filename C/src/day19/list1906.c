/* Replacing one process with another using execl(). */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    pid_t  pid ;
    
    pid = getpid();
    printf ("My pid = %u\n", pid);
    
    puts ("Executing /bin/ps.");
    execl ("/bin/ps", "** prog **", "u", NULL);

    puts("An error occured.");
    perror("list1902");
    return 0;
}
