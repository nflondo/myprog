#include <stdio.h>
int main() {
    int numNames;
    char firstName[101], lastName[101];

    scanf("%d", &numNames);

    for(int i = 0; i<numNames; i++){
        scanf("%s %s", firstName, lastName);    
        printf("%s %s\n", lastName, firstName);
    }
return 0;
}