/** Activity: find the end of the file
 *  You would like to find out whether the students in your class did better on 
 * the most recent assignment than the students in your colleagues' classes. 
 * The average grades of all these classes are stored in a file called "gradeComparison.txt". 
 * The first number stored in the file represents the average grade of the students in your class. 
 **/

#include <stdio.h>

int main(void) {
    FILE *ifile;  
    double num, firstNum;
    int N;
    double betterNum;
    
    ifile = fopen("gradeComparison.txt", "r"); 
                                
    N=1;    
    //fscanf(ifile, "%lf", &firstNum); // get my average
    //betterNum = firstNum;
    while (fscanf(ifile, "%lf", &num) != EOF) { // EOF is part of stdio.h        
        if ( N == 1){
            firstNum = num;
        }
        else if(num > firstNum){
           betterNum  = num;
           printf("No %d", N);
           fclose(ifile);
           return 0;
        }
        //printf("I read %d from the file. \n", num);
        //sum += num;
        N++;
    }
    printf("Yes");
    fclose(ifile);
    
    //printf("There are %d numbers in the file.\n", N);
    //printf("The sum of the numbers read is %d.\n", sum); 
    //printf("The average is %.2f.", (float) sum / N);
    
    return(0);
}
