// Read until the end of the file
#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int i, num, sum;
    int N;
    
    ifile = fopen("numbers.txt", "r"); 
                                
    N=0;
    sum = 0;
    
    while (fscanf(ifile, "%d", &num) != EOF) { // EOF is part of stdio.h
        printf("I read %d from the file. \n", num);
        sum += num;
        N++;
    }
    
    fclose(ifile);
    
    printf("There are %d numbers in the file.\n", N);
    printf("The sum of the numbers read is %d.\n", sum); 
    printf("The average is %.2f.", (float) sum / N);
    
    return(0);
}

