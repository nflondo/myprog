/* Demonstrates a simple do...while statement */

#include <stdio.h>

int get_menu_choice( void );

int main(void)
{
    int choice;

    choice = get_menu_choice();

    printf("You chose Menu Option %d\n", choice );
      
    return 0;
}

int get_menu_choice( void )
{
    int selection = 0;

    do
    {
        printf("\n" );
        printf("\n1 - Add a Record" );
        printf("\n2 - Change a record");
        printf("\n3 - Delete a record");
        printf("\n4 - Quit");
        printf("\n" );
        printf("\nEnter a selection: " );

        scanf("%d", &selection );

     }while ( selection < 1 || selection > 4 );

     return selection;
}
