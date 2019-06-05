/* 
 * Ex 3.15 using shared memory  
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
/* size (in bytes) of shared memory object*/
const int SIZE = 4096;
/* name of the shared memory object */
const char *name = "OS";
/* shared memory file descriptor */
int shm_fd;
/* pointer to shared memory object */
void *ptr;
/* whenever we deal with a process use pid_t data type */
pid_t pid;

	if (argc != 2){
		fprintf(stderr, "No number typed on the command line.\n");
		return (EXIT_FAILURE);
	}
	int number = atoi(argv[1]);  // converts string to int
	if (number < 0){
		fprintf(stderr, "***Error, negative number.\n");
		return (EXIT_FAILURE);
	}

	/* Create shared-memory object using shm_open */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	
	/* Configure the size of the object in bytes */
	ftruncate(shm_fd, SIZE);
	
	/* memory map the shared memory object */
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	pid = fork();
	
	if (pid == 0) {
/*		printf("%d ", number); */
		sprintf(ptr, "%d ", number);		
/*		ptr += strlen(number);  */
		while(number != 1){			
			if (number % 2 == 0)
				number = number/2;
			else 
				number = 3 * number + 1;
			
/*			printf("%d ", number); */
			sprintf(ptr, "%d ", number);			
/*			ptr += strlen(number);  */
		}		
	}
	else if (pid > 0){		
		wait(NULL); 
		printf("child complete.\n");
		printf("%s ", (char *)ptr);  
		/* remove the shared memory object */
		shm_unlink(name);  
	}
	
	return 0;
}
