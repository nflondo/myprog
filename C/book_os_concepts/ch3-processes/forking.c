/*forking */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;
	pid = fork();
	
	if (pid == 0) 
		execlp("/bin/ls","ls",NULL);					
	else if (pid > 0){
		wait(NULL);
		printf("child complete");
	}				
	
	
	return 0;	
}
