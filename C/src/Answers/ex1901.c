#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(char *command);

int main (void)
{    

    my_system ("/bin/ls");
    
    printf ("Done\n");
    
    return 0;
}

int my_system(char *command)
{
    pid_t    pid;
    int        status;
    
    pid = fork();
    if (pid == -1)
        return -1;
    if (pid == 0)
    {
        execl(command, command, NULL);
    }

    wait (&status);
    
    return status;
}
