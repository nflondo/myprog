/* Trapping SIGCHLD to prevent zombie child processes. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void  sigchld_handler (int);

int main(void)
{
    pid_t  pid;
    struct sigaction sig_struct;
    int    k;
    
    sig_struct.sa_handler = sigchld_handler;
    sigemptyset(&sig_struct.sa_mask);
    sig_struct.sa_flags = 0;

    if (sigaction(SIGCHLD,&sig_struct,NULL) != 0)
    {
        perror ("error") ;
        exit (1);
    }

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
 
        puts("Parent: going to sleep for 30 seconds."); 
        for (k=0; k<30; k++)
            sleep(1);
        puts("\nParent: Exiting.");
    }

    return 0;
}

void  sigchld_handler (int sig)
{   
    pid_t  pid;
    int    status;

    while ((pid = waitpid (-1, &status,  WNOHANG)) > 0)
    {
        printf("SIGCHLD: child with pid %u ", pid);
        if (WIFEXITED(status) != 0)
            printf("exited with status %d\n", WEXITSTATUS(status));
        else
            printf("exited abnormally.\n");
    }

}
