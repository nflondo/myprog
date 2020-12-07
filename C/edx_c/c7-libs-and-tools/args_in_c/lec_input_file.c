// Read numbers (integers and doubles) from a file using fscanf()
#include <stdio.h>

int main(void){
    FILE *ifile; // ifile can be any var name.  FILE is a varible type. File pointer

    int i, num, N;
    ifile = fopen("input_file.txt","r"); // open file for reading

    fscanf(ifile, "%d", &N); // Read first number from file.  Just like scanf(), the
                            // only difference is the file pointer that gets passed in.

    printf("There are %d numbers in the file.\n", N);

    for (i = 0; i < N; i++){
        fscanf(ifile, "%d", &num); // read one number at a time from file
        printf("I read %d from the file.\n", num); // print each number read in
    }

    fclose(ifile);
}