/* Inputs two floating-point values from the keyboard and then displays their product */

#include <stdio.h>

float do_product(float a, float b);

int main(void){
 
 float num1, num2, result= 0 ;
 
 puts( "\nEnter two values: " );
 scanf( "%f %f", &num1, &num2 );
  
 result = do_product(num1, num2);
 
 printf("The product of a and b is:%f\n", result);
 
 return 0;

}

float do_product(float a, float b){
 float res;
 
 res= a * b;
 return res;
 
}
