#include <stdio.h>
int main() {
    int numRep = 0;
    char myWord[101];
    scanf("%d", &numRep);
    scanf("%s", myWord);
    for(int i = 0; i < numRep; i++){
        printf("%s\n", myWord);
    }

return 0;
}