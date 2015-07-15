/* Using getpid() and getppid(). */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t  pid;
    
    pid = getpid();
    printf ("My pid = %u\n", pid);
    
    pid = getppid();
    printf ("My parent's pid = %u\n", pid);

    return 0;
}
