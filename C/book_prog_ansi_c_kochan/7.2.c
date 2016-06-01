#include <stdio.h>
/*  Playing with arrays        */

main()
{
	int values[10];
	int index;
	//init to 0	
	for (index =0; index < 10; ++index)
		values[index]=0;

	//verify
    for (index =0; index < 10; ++index)
		printf("values[%i] = %i\n", index, values[index]);

	values[0] = 197;
	values[2] = -100;
	values[5] = 350;
	values[3] = values[0] + values[5];
	values[9] = values[5] / 10 ;
	--values[2];

	for (index =0; index < 10; ++index)
		printf("values[%i] = %i\n", index, values[index]);
}
