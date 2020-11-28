#include <stdio.h>
#include "weatherstats.h"

int main(void) {
    int N = 10;

    double temperatures[] = {60, 71.5, 88, 55.5, 49, 33.5, 32, 44.5, 49.0, 50};
    double average = averageTemp(temperatures, N);
    printf("Average %d-day temp: %.2lf\n", N, average);

    return 0;
}
