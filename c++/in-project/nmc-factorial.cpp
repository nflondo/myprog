// 05_challenge
#include <cstdio>

int get_factorial(int n){
    // n! = n * (n-1) * (n-2) * (n-3)...
    int result = n;
    printf("n (initial): %d\n", n);
    while(n > 1){
        result *= (n-1);
        printf("n (inside for loop): %d\n", n);
        printf("result: %d\n", result);
        n--;
    }
    return result;
}

int main(){
    //puts ("Enter a number: ");
    int number=5;
    printf("Factorial of %d is %d\n", number, get_factorial(number));
}