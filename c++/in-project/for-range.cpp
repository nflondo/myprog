#include <cstdio>

int main(){
    //int array[] = { 1, 2, 3, 4, 5 };
    char s[] = "mystring";

    //for(int i : array) { //declare var : <container> //var gets set
    //to value in the container
    for(char c : s){ //this type of look is not as convenient for strings

        //printf("i is: %d\n", i);
        if(c == 0) break;
        printf("c is: %c\n", c);
    }
    return 0;
}