/* Demonstrates using pointer arithmetic to access */
/* array elements with pointer notation. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct {
struct msg {
	char *p2; // uninitalized
	char p1[30];
//}msg;
}myptrs;
//msg myptrs;
    	
	

int main(void)
{
	//myptrs.p2 = malloc(20);	// This initilizes *p2 inside msg structure
	char name[]="some text"; //this two lines initilize 
	myptrs.p2=name;          //   *p2 inside msg structure as well
	strcpy(myptrs.p1, "Teach yourself in 31 days");
	strcpy(myptrs.p2, "By SAMs publishing");

	puts(myptrs.p1);
	puts(myptrs.p2);
     return 0;
}
