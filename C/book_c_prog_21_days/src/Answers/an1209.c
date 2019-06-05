#include <stdio.h>

int main(void)
{	void *ptr = NULL ;
	fprintf (stdout, "stdout\n");
	fprintf (stderr, "stderr\n");
	
	ptr ++ ;
	
	printf ("ptr = %p\n", ptr);
	
	return 0;
};
