// 07_challenge.  Build a template version of the non-recursive factorial
#include <cstdio>
#include <iostream>

// int get_factorial(int n){
//     // n! = n * (n-1) * (n-2) * (n-3)...
//     int result = n;
//     printf("n (initial): %d\n", n);
//     while(n > 1){
//         result *= (n-1);
//         printf("n (inside for loop): %d\n", n);
//         printf("result: %d\n", result);
//         n--;
//     }
//     return result;
// }

template <typename T>
T get_factorial ( T n){
    T result = n;
    while(n > 1){
        result *= (n-1);
        n--;
    }
    return result;
}

int main(){
    //puts ("Enter a number: ");
    int number=5;
    //std::cout << get_factorial(6) << std::endl;
    printf("Factorial of %d is %d\n", number, get_factorial(number));
    
    long long unsigned int llui = 15;
    printf("%lld! is %lld\n", llui, get_factorial(llui));

    long double ld = 25;
    printf("%.3Lf! is %-4.10Lg\n", ld, get_factorial(ld));

    return 0;
}