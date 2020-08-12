#include <stdio.h>

int main(void) {
    int numMembersPerTeam =0, playerWeight = 0, teamOneWeight = 0;
    int teamTwoWeight = 0;

    scanf("%d", &numMembersPerTeam);

    for(int i = 0; i < numMembersPerTeam * 2; i++){
        scanf("%d", &playerWeight);
        if ( i % 2){
            teamTwoWeight += playerWeight;
        } else
        {
            teamOneWeight += playerWeight;
        }        
    }

    if (teamOneWeight > teamTwoWeight){
        printf("Team 1 has an advantage\n");                
    } else {
        printf("Team 2 has an advantage\n");        
    }
    printf("Total weight for team 1: %d\n", teamOneWeight);
    printf("Total weight for team 2: %d\n", teamTwoWeight);
    return 0;
}