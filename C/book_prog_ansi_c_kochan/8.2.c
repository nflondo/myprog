#include <stdio.h>
/* Calculate nth triangular number */

int calculate_triangular_number (int n){
    int i, triangular_number = 0;
    
    for ( i = 1; i <= n; ++i)
        triangular_number = triangular_number + i;
        
    //printf ("Triangular number %i is %i\n", n, triangular_number);
    return (triangular_number);
    
}

main(){
    int counter, number;
    for (counter =1; counter <=3 ; ++counter){
        printf ("What triangular number do you want?: ");
        scanf ("%i", &number);
        
        printf ("Triangular number %i is %i\n", number, calculate_triangular_number (number));
        
    
    }
    

}
