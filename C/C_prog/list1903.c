/* Starting another process using fork(). */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t  pid;
    int    x=13;
    
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
        printf("Child : x = %d, ", x);
        x = 10;
        printf("new x = %d\n", x);
        sleep(2);
        puts ("Child : about to exit.");
        exit(42);
        puts ("Child : You'll never see this.");
    }
    else
    {   
        printf("Parent: pid = %u. Child's  pid = %u\n", 
                getpid(), pid);
        puts("Parent: going to sleep for 60 seconds."); 
        sleep(60);
        puts("Parent: waking up."); 
        printf("Parent: x = %d\n", x);
    }

    return 0;
}
