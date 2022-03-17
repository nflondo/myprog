// working.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

//Reference function
const int & f(const int & i) {
    return i;
}
int main()
{
    //Formatting
     puts("Hello, World");
     //fputs("Hello, World", stdout); //output stream for console. No \n

     const int bufsize = 256; //bytes
     static char buf[bufsize];
     fputs("prompt: ", stdout);
     //fgets(char *, int, FILE *);
     fgets(buf, bufsize, stdin);
     puts("output: ");
     fputs(buf, stdout);//asynchronous (may happer later)
     fflush(stdout); //puts a block until fputs it's finished writing

    // Writing files
    // static const char * fn1 = "file1";
    // static const char * fn2 = "file2";
    //rename(fn1, fn2);  //renames an existing file
    //remove(fn2); // return 0 on success


    // FILE * fh = fopen(fn1, "w");
    // fclose(fh);  

    
    // const int i = 7;
    // printf("value of constant is %d\n", i);
    
    // puts("Hello, World!");

    // char s[] = "my string";  //terminated with null(0)
    // printf("s is: %s\n", s);

    // char s2[] = {'m', 'y'};
    // printf("s2 is: %s\n", s2);

    // for(int i = 0; s[i] != 0; ++i){
    //     printf("char is: %c\n", s[i]);
    // }
//print array using pointers
    // for(char * cp = s; *cp != 0; ++cp){
    //     printf("char *val is: %c\n", *cp);
    // }

    // int x = 42;
    // int y = 7;

    // printf("value is: %d\n", x < y);

    // if(x > y){ // 0 = false, any non-zero = true
    //     puts("condition is true");
    // } else {
    //     puts("condition is false");
    // }
    // int array[] = {1,2,3,4,5};
    // int i2 = 0;
    // while(i2 < 5){
    //     if( i2 == 3) break;
    //     printf("element %d is: %d\n", i2, array[i2]);
    //     ++i2;
    // }
    // //References.  It's useful cause it doesn't make a copy
    // int j = 5;
    // int & jr = j; //reference
    // jr = 10;
    // printf("j is %d\n", j);
    // printf("f(j) is %d\n", f(j));

    return 0;
}
