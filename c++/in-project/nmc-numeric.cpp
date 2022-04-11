// numeric.cpp by Bill Weinman <http://bw.org/>
// updated 2002-07-27
#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
    //int neg = -47;
    //.int x = abs(neg);
    double x = exp(1); //e raised to the given argument
    double x = log(2);
    
    double x = pow(2, 10); //2 to power of 10
    double x = sqrt(1024);
    const double pi = acos(-1);
    double x = sin(pi/4);

    printf("x is %lf\n", x);
    return 0;
}
