/* Activity: read numbers from a file.
 you need to compute the average grade your students have received on the most 
 recent assignment. These grades (integers) are stored in the file studentGrades.txt.
*/
#include <stdio.h>

int main(void){
    int numGrades, grade,i,sum = 0;
    double avg = 0;

    FILE *ifile;
    ifile = fopen("studentGrades.txt", "r");
    fscanf(ifile, "%d", &numGrades);

    for(i = 0; i < numGrades; i++){
        fscanf(ifile, "%d", &grade);
        sum += grade;
    } 
    avg = sum / (double)numGrades;
    printf("%.2lf", avg);
}