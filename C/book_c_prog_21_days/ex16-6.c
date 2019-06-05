/* which macros return true for int var = 1 ?
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (void){
char var = 65;
int result;

	result = isascii(var);
	printf("var: %d, isascii: %d\n", var, result);
	result = iscntrl(var);
	printf("iscntrl: %d\n", result);
	result = isalnum(var);     
	printf("isalnum: %d\n", result);
	result = isdigit(var);     
	printf("isdigit: %d\n", result);
	
	result = isgraph(var);     
	printf("isgraph: %d\n", result);
	result = isprint(var);     
	printf("isprint: %d\n", result);
	result = isupper(var);     
	printf("isupper: %d\n", result);
	
	
return 0;
}