#include <stdio.h>
/* Calculate absolute value of a number */
float absolute_value (float x){
    if ( x < 0 )
        x = -x;
    return (x);
}

/* Compute square root of a number */
float square_root (float x, float epsilon){
    //float epsilon = .00001;
    float guess = 1.0 ;
    
    while ( absolute_value (guess * guess - x) >= epsilon )
    {
        guess = (x / guess + guess ) / 2.0;
        printf ("Guess: %f\n", guess);
    }
    return guess;
}

main(){
    printf ("square_root (144.0) = %f\n", square_root(144.0, .00001) );
    printf ("square_root (144.0) = %f\n", square_root(144.0, .01) );

}
