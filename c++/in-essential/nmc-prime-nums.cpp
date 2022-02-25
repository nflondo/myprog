/* Write a program that calculates the first 25 prime numbers (that is all the 
prime numbers under 100) 
Prime number = can only be divided evenly by itself and one (it's only factors 
are itself and one)
Natural number is a positive number with no fractional part, it must be greater 
than one. 
*/
#include <cstdio>

bool is_prime(int num){

    for(int i = 2; i < num; i++){
        if (num % i == 0){
            //printf("number: %d is NOT prime\n", num);
            return false;
        } //else {
        //    printf("number: %d is prime", num);
        //}
    }
    return true;
}

int main(){
    int count=1;
    for(int i = 2; i < 100; i++){
        if (is_prime(i) && count < 26){
            printf("%d - number: %d is prime\n", count, i);
            count++;
        }
    }    
}