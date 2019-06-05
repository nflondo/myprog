/* Inputs a list of strings from the keyboard, sorts them */
/* in ascending or descending order, then displays them */
/* on the screen. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 25

int get_lines(char *lines[]);
void sort(char *p[], int n, int sort_type);
void print_strings(char *p[], int n);
int alpha(char *p1, char *p2);
int reverse(char *p1, char *p2);

char *lines[MAXLINES];

int main(void)
{
	int number_of_lines, sort_type;

	/* Read in the lines from the keyboard. */

	number_of_lines = get_lines(lines);

	if ( number_of_lines < 0 )
	{
		puts("Memory allocation error");
		exit(-1);
	}

	puts("Enter 0 for reverse order sort, 1 for alphabetical: ");
	scanf("%d", &sort_type);

	sort(lines, number_of_lines, sort_type);
	print_strings(lines, number_of_lines);
    return 0;
}

int get_lines(char *lines[])
{
	int n = 0;
	char buffer[80];	/* Temporary storage for each line. */

	puts("Enter one line at a time; enter a blank when done.");

	while (n < MAXLINES && fgets(buffer,80,stdin) != 0 && buffer[0] != '\n')
	{
		if ((lines[n] = (char *)malloc(strlen(buffer)+1)) == NULL)
			return -1;
		strcpy( lines[n++], buffer );
	}
	return n;

}	/* End of get_lines() */

void sort(char *p[], int n, int sort_type)
{
	int a, b;
	char *x;

	/* The pointer to function. */

	int (*compare)(char *s1, char *s2);

	/* Initialize the pointer to point to the proper comparison */
	/* function depending on the argument sort_type. */

	compare = (sort_type) ? reverse : alpha;

	for ( a = 1; a < n; a++)
	{
		for ( b = 0; b < n-1; b++ )
		{
			if (compare(p[b], p[b+1]) > 0)
			{
			x = p[b];
			p[b] = p[b+1];
			p[b+1] = x;
			}
		}
	}
}	/* End of sort() */

void print_strings(char *p[], int n)
{
	int count;

	for (count = 0; count < n; count++)
		printf("%s", p[count]);
}

int alpha(char *p1, char *p2)
/* Alphabetical comparison. */
{
	return(strcmp(p2, p1));
}

int reverse(char *p1, char *p2)
/* Reverse alphabetical comparison. */
{
	return(strcmp(p1, p2));
}
