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
        sleep(10);
        puts ("Child : about to exit.");
        exit(33);
    }
    else
    {   
        printf("Parent: pid = %u. Child's  pid = %u\n", 
                getpid(), pid);
        
        while ((pid = waitpid (-1, &status,  WNOHANG)) == 0)
        {   
            printf("Parent: No child has terminated.");
            puts(" Going to sleep for 1 second."); 
            sleep(1);
        }
            
        printf("Parent: child with pid %u ", pid);
        if (WIFEXITED(status) != 0)
            printf("exited with status %d\n", WEXITSTATUS(status));
        else
            printf("exited abnormally.\n");
    }

    return 0;
}
