#include <stdio.h>
#include <stdlib.h> // for exit()

int main(void){
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    // Open file for reading or fail
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file: %s\n", filename);
        exit(0);
    }

    printf("Enter the filename to write to: ");
    scanf("%s",filename);
    // open file for writing or fail
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file for writing: %s\n", filename);
        exit(0);
    }
    // Read contents from source file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("\nContents copied to %s\n", filename);

    fclose(fptr1);
    fclose(fptr2);
    return 0;

}