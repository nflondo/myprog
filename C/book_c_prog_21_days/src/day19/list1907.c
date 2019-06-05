/* A simple example of signal handling. */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void  sig_handler(int sig);

static int exit_now = 0;

int main(void)
{
    struct sigaction sig_struct ;
    
    sig_struct.sa_handler = sig_handler;
    sigemptyset(&sig_struct.sa_mask);
    sig_struct.sa_flags = 0;
    
    if (sigaction(SIGINT,&sig_struct,NULL) != 0)
    {
        perror ("error") ;
        exit (1);
    }
    
    puts("Press Control-C to end processing.");
    while (exit_now == 0)
    {
        puts("Processing.");
        sleep(1);
    }
    
    puts("Saving data to disk.");
        
    return 0;
}

void  sig_handler(int sig)
{
    printf("Received signal %d. Exiting soon.\n", sig);
    exit_now = 1;
}
