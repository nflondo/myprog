/* Write numbers to a file using fprintf()
*
*/
#include <stdio.h>

int main(void){
    FILE *ofile; 

    char filename[] = "output_file.txt"; // string var
    int num;

    ofile = fopen(filename, "w"); // creates file if it doesn't exits or overwrites it

    do{
        printf("Please entere a grade. Enter -1 to quit: \n");
        scanf("%d", &num);
        if(num != -1)
            fprintf(ofile, "%d ", num); // leave a space after number
    }while(num != -1);
    fclose(ofile);

    return 0;
}

