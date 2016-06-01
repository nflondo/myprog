#include <stdio.h>
/* Sort an array of int into ascending order*/

void sort(int a[], int n, int order){
	int i,j,temp;

	        for (i=0; i < n - 1; ++i)
		        for (j = i + 1; j < n; ++j)
			        if ( order == 1 && a[i] > a[j] || order == -1 && a[i] < a[j])
			        {
				        temp = a[i];
				        a[i] = a[j];
				        a[j] = temp;
			        }
} // sort

main(){
	int i;
	int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 };

	printf ("The array before the sort:\n");
	for (i =0; i< 16; ++i )
		printf("%i ", array[i]);

	sort (array, 16, 1);

	printf ("\n\nThe array after the sort (ascending):\n");

	for (i =0; i< 16; ++i )
		printf("%i ", array[i]);

	printf ("\n");
	
	sort (array, 16, -1);
	printf ("\n\nThe array after the sort (descending):\n");

	for (i =0; i< 16; ++i )
		printf("%i ", array[i]);

	printf ("\n");

}
