/**  Activity: write numbers to a file
 * The program should first read, from the user input, the grade (an integer)
 * that you need to check on. Next, the program should open the file "myGrades.txt",
 * find the last number in the file, close the file, and compare the last number from 
 * the file to the grade read from the user input. If the two grades are equal then 
 * you presumably already recorded the grade and don't have to do anything. If on 
 * the other hand the two grades do not equal each other then you have not yet recorded
 *  this new grade and need to do so by appending this new grade to the file.
* Finally, reopen the file and print its new contents to the screen.
 **/
#include <stdio.h>

int main(void){
    FILE *ifile, *ofile;  
    int userGrade,grade;

    scanf("%d", &userGrade);

    ifile = fopen("myGrades.txt", "r"); 
    while (fscanf(ifile, "%d", &grade) != EOF) { // EOF is part of stdio.h        

    }
    //printf("Last grade found:%d ", grade);
    fclose(ifile);

    if (userGrade != grade){
        ofile = fopen("myGrades.txt", "a");
        fprintf(ofile, " %d", userGrade);
        fclose(ofile);
    }
    ifile = fopen("myGrades.txt", "r"); 
    while (fscanf(ifile, "%d", &grade) != EOF) { // EOF is part of stdio.h        
        printf("%d ", grade);        
        //   return 0;
    }
    fclose(ifile);
      
return 0;
}