
#include <stdio.h>

void print_letter2(void);

/*int ctr;*/



int main (void){
int ctr;
char letter1 = 'X';
 for(ctr =0; ctr < 10; ctr++){
   printf("%c", letter1);
   print_letter2();
  }
 puts("");
 return 0;
}

void print_letter2(void){
int ctr;
char letter2 = '=';
 for(ctr=0; ctr <2; ctr++){
  printf("%c", letter2);
 }

}
