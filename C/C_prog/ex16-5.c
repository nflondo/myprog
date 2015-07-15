/* Prompts user for last name, first name, and middle name individually
** Display in this format B. L. Jones
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void){
char lname[60],	fname[60], mname[60], dest[160];

	puts("Last Name:");
	fgets(lname,60,stdin);
	
	puts("First Name:");
	fgets(fname,60,stdin);

	puts("Middle Name:");
	fgets(mname,60,stdin);
	
	strncpy(dest, fname,1);
	strcat(dest, ". ");
	strncat(dest, mname,1);
	strcat(dest, ". ");
	strcat(dest, lname);
	
	puts(dest);
	
return 0;
}