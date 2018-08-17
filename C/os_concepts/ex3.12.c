/*Creates a Zombie process by exiting the child process before the parent
 * terminates.  Leap kills the zombie process automatically once the parent
 * terminates.
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;
	pid = fork();
	
	if (pid == 0) {
		execlp("/bin/ls","ls",NULL);	
		exit(0);
	}
	else if (pid > 0){
		sleep(50);
		//wait(NULL);  This will make it a zombie process
		printf("child complete");
	}				
	
	
	return 0;	
}
