/* https://clanguagetutorialsite.wordpress.com/2016/05/09/split-number-into-digits-in-c-programming-extract-digits-from-integer-in-c-language/
*/
#include<stdio.h>

int main(){

  int num,temp,factor=1;

  printf("Enter a number: ");

  scanf("%d",&num);

  temp=num;

  while(temp){
      printf("temp = %d\n", temp);
      temp=temp/10;

      factor = factor*10;
      printf("factor loop = %d\n", factor);

  }

  printf("factor = %d\n", factor);

  printf("Each digits of given number are: ");

  while(factor>1){

      factor = factor/10;

      printf("%d ",num/factor);

      num = num % factor;

  }

  return 0;

}