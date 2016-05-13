#include <stdio.h>

main()
{
    int number, tnum;
    printf (" Number     Triangular Num\n");
    tnum=0;
    for (number=5; number<=50 ; number = number + 5){
        tnum = number * (number + 1)/2 ;
        printf ("%2i     %2i\n",number, tnum);        
    
    }


}
