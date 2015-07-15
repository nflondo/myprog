/* Using qsort() and bsearch() with values.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int intcmp(const void *v1, const void *v2);

int main(void)
{
    int arr[MAX], count, key, *ptr;

    /* Enter some integers from the user. */

    printf("Enter %d integer values; press Enter after each.\n", MAX);

    for (count = 0; count < MAX; count++)
        scanf("%d", &arr[count]);

    puts("Press Enter to sort the values.");
    getc(stdin);

    /* Sort the array into ascending order. */

    qsort(arr, MAX, sizeof(arr[0]), intcmp);

    /* Display the sorted array. */

    for (count = 0; count < MAX; count++)
        printf("\narr[%d] = %d.", count, arr[count]);

    puts("\nPress Enter to continue.");
    getc(stdin);

    /* Enter a search key. */

    printf("Enter a value to search for: ");
    scanf("%d", &key);

    /* Perform the search. */

    ptr = (int *)bsearch(&key, arr, MAX, sizeof(arr[0]),intcmp);

    if ( ptr != NULL )
        printf("%d found at arr[%d].\n", key, (ptr - arr));
    else
        printf("%d not found.\n", key);
    return 0;
}

int intcmp(const void *v1, const void *v2)
{
    return (*(int *)v1 - *(int *)v2);
}
