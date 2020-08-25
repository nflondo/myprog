
/*You just computed final scores for all of the students in your classroom and 
would like to tell each student their ranking when compared to the other students 
in your class. For example, if Remi's score is 14, Yan's score is 2 and Maria's 
score is 20 then Remi's ranking is 2 since he has the second highest score, Yan's 
ranking is 3 since he has the lowest score and Maria's ranking is 1 since she has the highest score amongst the three students.

You'll be given the following inputs: first the number of students, then all of 
the students' final scores, then finally, all of the students' names. Be sure to look at the example below.

Your output should be one line per student, with each line displaying the student's 
name followed by "rank is" followed by the student's rank.

The order in which names are displayed in the output should be the same as the order 
given in the input. The ranking starts at 1 (meaning this student has the highest score), 2 for the second highest grade etc...*/
#include <stdio.h>
int main(void) {
    int numStudents; 
    char names[51];   
    int j, i, swap;

    scanf("%d", &numStudents);
    int finalScores[numStudents + 1];  
    // Initialize int array to all zeros to avoid weird values
    for(int i = 0; i < numStudents +1 ; i++){
        finalScores[i] = 0;
    }
    int trackOriginalScore[numStudents + 1];
    // Initialize array to all zeros
    for(int i = 0; i < numStudents +1 ; i++){
        trackOriginalScore[i] = 0;
    }    
    int ranking[numStudents + 1];
    // Initialize array to all zeros
    for(int i = 0; i < numStudents +1 ; i++){
        ranking[i] = 0;
    }
    // Enter scores
    for(int i = 0; i < numStudents; i++){
        scanf("%d", &finalScores[i]);
        trackOriginalScore[i] = finalScores[i];
    }
    // sort scores in descending order and get ranking

    for (j=0; j< numStudents-1; j++) {
        for (i=0; i< numStudents-1; i++) {
            if (finalScores[i] < finalScores[i+1]) {
                swap = finalScores[i];
                finalScores[i] = finalScores[i+1];
                finalScores[i+1] = swap;
            }
        }
    }

    // Print sorted array
//    for(int i = 0; i < numStudents; i++){
//        printf("%d ", finalScores[i]);
//    }

    //j = 0;
//    for(int i = numStudents, j = 0; i >= 0; numStudents--, j++){
 //       finalScores[i] = ranking[j];
        //j++;
   // }
/*
  printf("\ntrackOriginalScore list: \n");
    for (i=0; i<numStudents; i++) {
        printf("%d ", trackOriginalScore[i]);
    }
*/

    for(int i = 0; i < numStudents; i++){
        scanf("%s", names);
        j = 0;
        while (trackOriginalScore[i] != finalScores[j] && finalScores[j] != '\0')
        {
            j++;
        }
        printf("%s rank is %d\n", names,  j + 1);        
    }

return 0;
}