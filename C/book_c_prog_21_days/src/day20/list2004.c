/* Accessing command-line arguments using getopt(). */

#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
    int option;

    while ((option = getopt (argc, argv, "abi:o:z")) != EOF)
    {
        switch (option)
        {
            case 'a' :
            case 'b' :
            case 'z' :
                    printf("option : %c\n", option);
                    break;
                    
            case 'i' :
                    printf("input  : %s\n", optarg);
                    break;
                    
            case 'o' :
                    printf("output : %s\n", optarg);
                    break;
        
            default: 
					exit(0);
        }
    }

    for ( ; optind < argc ; optind++)
        printf ("opt %2d : %s\n", optind, argv [optind]);

    return 0;
}
