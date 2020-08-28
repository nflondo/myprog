/* Sum of digits.  Formula sum = n + number to the left
Please write a C-program that uses a recursive function called "sumOfDigits()" 
to compute the sum of the digits of a number. To do so, your main function should 
first read an integer number as input and then call sumOfDigits(), which should in 
turn call itself until there are no digits left to sum, at which point the final 
sum should display to the user.
Here is the main idea of how the recursion in sumOfDigits() should work:
sumOfDigits(6452) = 2 + sumOfDigits(645)
sumOfDigits(645) = 5 + sumOfDigits(64)
...
sumOfDigits(6) = 6
*/


#include <stdio.h>

int sumOfDigits(int num);

int main(){
    int digit, sum;
    scanf("%d", &digit);

    sum = sumOfDigits(digit);
    printf("%d", sum);

    return 0;
}

int sumOfDigits(int num){
    int modResult;
    if (num < 10){
        return num;
    } else {
        // num/10 returns the num minus the right-most number   
        return (sumOfDigits(num/10) + num % 10);
    }
}