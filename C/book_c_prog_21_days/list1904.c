/* Using wait() to wait for a child process. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t  pid;
    int    status;
    
    pid = fork();
    
    if (pid < 0)
    {   
        printf("Error : fork () returned %u.\n", pid);
        exit(1);
    }
        
    if (pid == 0)
    {   
        printf("Child : pid = %u. Parent's pid = %u\n", 
                getpid(), getppid());
        sleep(1);
        puts ("Child : about to exit.");
        exit(42);
    }
    else
    {   
        printf("Parent: pid = %u. Child's  pid = %u\n", 
                getpid(), pid);
        puts("Parent: going to sleep for 10 seconds."); 
        sleep(10);
        puts("Parent: waking up."); 

        pid = wait(&status);
        printf("Parent: child with pid %u ", pid);
        if (WIFEXITED(status) != 0)
            printf("exited with status %d\n", WEXITSTATUS(status));
        else
            printf("exited abnormally.\n");
        puts("Parent: going to sleep for another 30 seconds."); 
        sleep(30);
    }

    return 0;
}
