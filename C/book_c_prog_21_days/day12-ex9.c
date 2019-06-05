/* Menu with 5 options, the fifth to quit, the others execute a system command*/
#include <stdio.h>
#include <stdlib.h>

void clear_kb(void);

int main(void){

int myinput; 
 while(1){
   /* char input[1];*/
  
        printf( "\n     MENU");
        printf( "\n   ========\n");
        printf( "\n1.  Current dir path");
        printf( "\n2.  Date and Time");
        printf( "\n3.  SLES version");
        printf( "\n4.  Memory Info");
        printf( "\n5.  Quit");
        printf( "\n\nEnter Selection ==> ");

  /*fflush(stdin);   remove extra characters from keyboard buffer */
  myinput = getchar();
   clear_kb() ;
/*  fgets(input,10,stdin);*/
 
	switch ( myinput ){

		case '1':
        printf( "\n   >>>>>===Results====<<<<<\n");
		 system("pwd");
        printf( "\n   >>>>>>========<<<<<<<<\n"); 
		 		 break;
		case '2':
		printf( "\n   >>>>>===Results====<<<<<\n");
		 system("date"); 
		  printf( "\n   >>>>>>========<<<<<<<<\n");
		 		 break;
		case '3':
		printf( "\n   >>>>>===Results====<<<<<\n");
		 system("cat /etc/SuSE-release"); 
		  printf( "\n   >>>>>>========<<<<<<<<\n");
		 		 break;
		case '4':
		printf( "\n   >>>>>===Results====<<<<<\n");
		 system("free");
		  printf( "\n   >>>>>>========<<<<<<<<\n"); 
		 		 break;
		case '5':
		 puts("Bye bye");
		 exit(0);
		
		default: 
		 printf("Invalid optioin, try again...\n");
		 break;
		 
 	}/*switch*/

 }/*while*/

 return 0;

}
void clear_kb(void)
{
    char junk[80];
    fgets(junk, 80, stdin);
}


