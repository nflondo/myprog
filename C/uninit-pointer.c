/* Demonstrates using pointer arithmetic to access */
/* array elements with pointer notation. */

#include <stdio.h>
#include <string.h>

struct msg {
	char p1[30];
	char *p2; // uninitalized
}myptrs;

	//char name;	
	myptrs.p2 = "some text";	

int main(void)
{
	
	strcpy(myptrs.p1, "Teach yourself in 31 days");
	strcpy(myptrs.p2, "By SAMs publishing");

	puts(myptrs.p1);
	puts(myptrs.p2);
     return 0;
}
