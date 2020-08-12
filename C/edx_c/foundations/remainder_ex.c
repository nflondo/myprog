#include <stdio.h>
int main(void) {
    int numMatches = 0, boxSize = 0;
    int fullBoxes = 0, remainingMatches = 0;
    //printf("How tall are you (in meters)? ");
    scanf("%d", &numMatches);
    scanf("%d", &boxSize);
    // convert kil to miles
    fullBoxes = numMatches/boxSize;
    remainingMatches = numMatches%boxSize;
    //scanf("%lf", &height);
    printf("%d\n", fullBoxes);
    printf("%d\n", remainingMatches);
    return 0;
}
