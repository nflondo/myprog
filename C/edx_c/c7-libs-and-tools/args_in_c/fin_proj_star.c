/** Have to compile with math lib: gcc -Wall -o fin_proj_star fin_proj_star.c -lm
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
//add additional header files here

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

//void printStars(struct star mystars[], int N); 
//add your propotypes here
//int readStars(struct star *starptr);
int readStars(struct star starptr[]);
void tempPrintStars(struct star mystars[], int N);
void computeRadii(struct star starptr[], int N);
void classifyStars(struct star star_ptr[], int N);
void printStars(struct star mystars[], int N);

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;

    N = readStars(mystars);
//    printf("N: %d\n", N);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);
    tempPrintStars(mystars, N);

    return 0;
}

void tempPrintStars(struct star mystars[], int N){
    int i;
    for(i=0; i<N; i++){
        printf("name: %s ", mystars[i].name);
        printf("temp: %d ", mystars[i].temperature);
        printf("lum:  %lf ", mystars[i].luminosity);
        printf("radius:  %lf ", mystars[i].radius);
        printf("classification: %c \n", mystars[i].classification);
    }
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
        	printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
        	printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
        	printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
        	printf("Unclassified Star\n");
        } else {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.
void classifyStars(struct star star_ptr[], int N){
    int i;
    for(i=0; i < N; i++){
        // luminosity >= .01 && luminosity <= 1000,000 Vega
        if ( (star_ptr[i].luminosity >= pow(10, -2.0) && star_ptr[i].luminosity <= pow(10,6.0))
            && (star_ptr[i].radius >= 0.1 && star_ptr[i].radius <= 10.0)){
                star_ptr[i].classification = 'M';              
        // luminosity >= 1000 && luminosity <= 100,000
        } else if ((star_ptr[i].luminosity >= pow(10, 3.0) && star_ptr[i].luminosity <= pow(10,5.0))
            && (star_ptr[i].radius >= 10.0 && star_ptr[i].radius <= 100.0)){
                star_ptr[i].classification = 'G';            
        // luminosity >= 100,000 && luminosity <= 1000,000 Betelguese
        } else if ((star_ptr[i].luminosity >= pow(10, 5.0) && star_ptr[i].luminosity <= pow(10, 6.0))
            && (star_ptr[i].radius > 100.0)){
                star_ptr[i].classification = 'S';            
        }else if (star_ptr[i].radius < 0.01){
                star_ptr[i].classification = 'W';
        }else{
            star_ptr[i].classification = 'N';
        }                 
    }
}
void computeRadii(struct star starptr[], int N){
    double radius;
    double ts = 3500;
    int i;    
    // radius = pow((ts/temp), 2) * sqrt(lum)

    for(i=0; i < N; i++) {
        radius = pow((ts/starptr[i].temperature), 2.0) * sqrt(starptr[i].luminosity);
        starptr[i].radius = radius;
        //printf("radius: %lf", radius);
    }    
}

//int readStars(struct star *starptr){ //*starptf receives an array, also starptr[] should do it I think
int readStars(struct star starptr[]){ 
//startdata.txt:
//star_name temperature luminosity
    FILE *ifile;
    char star_name[50];
    int temp;
    double lum;
    int i=0;

    ifile = fopen("stardata.txt", "r");
    
    //fscanf(ifile, "%c", starptr->name);
    //fscanf(ifile, "%c", starptr[0].name);
    // need to put in local var first, cause fscanf won't accept var * 
    while (fscanf(ifile, "%s", star_name) != EOF){
        strcpy(starptr[i].name, star_name);
        fscanf(ifile, "%d", &temp );
        starptr[i].temperature = temp;
        fscanf(ifile, "%lf", &lum );
        starptr[i].luminosity = lum;
        i++;
    }

    fclose(ifile);
    return i;
}