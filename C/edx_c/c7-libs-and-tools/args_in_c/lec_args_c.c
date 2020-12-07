// These are the same: *argv[], **argv, argv[][] since it's a matrix, an array
// of pointers to characters (so arguments are received as strings by the program)
// Name of the program is included in the number of arguments
#include <stdio.h>
#include <stdlib.h> // for atoi and atof (ascii to integer)
#include <string.h> // for strcmp

int main(int argc, char *argv[]){
    int i, compare, wholeNumber;
    double decimalNumber;

    printf("I have %d arguments from the command line: \n", argc);
    for(i = 0; i < argc; i++){
        printf("Argument %d: %s\n", i, argv[i]);  // print all arguments passed
    }
    
    if (argc == 4){
        compare = strcmp(argv[1], "-e"); // Does it equal -e?
        if(compare == 0){
            printf("argv[1] equals \"-e\" \n");
        } else{
            printf("argv[1] does not equal \"-e\"\n");
        }
        wholeNumber = atoi(argv[2]); // convert to integer
        printf("%s as an integer is %d.\n", argv[2], wholeNumber);
        decimalNumber = atof(argv[3]); // convert to decimal (double, float)
        printf("%s as a dobule is %lf\n", argv[3], decimalNumber);
    }
    return 0;
}