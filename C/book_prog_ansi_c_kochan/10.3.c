#include <stdio.h>
/*Function determines if a character is alphanumeric*/
int alphabetic (char c)
{
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ((c >= '0' && c <= '9') || ( c >= '+' && c <= '.'))  )
		return (1);
	else
		return (0);
}

/* Function to read a line of text from terminal */
void read_line (char buffer[])
{
	char character;
	int i = 0;
	
	do
	{
		character = getchar();
		buffer[i] = character;
		++i;
	}
	while ( character != '\n' );

	buffer[i - 1] = '\0';
}

/* Function to count number of words in a string*/
int count_words (char string[])
{
	int i, looking_for_word = 1, word_count = 0;
	
	for ( i = 0; string[i] != '\0'; ++i )
		if ( alphabetic(string[i]) )
		{
			if ( looking_for_word )
			{
				++word_count;
				looking_for_word = 0;
			}
		}
		else
			looking_for_word = 1;
		
	return (word_count);
}

main()
{
	char text[81];
	int end_of_text = 0, total_words = 0;
	int count_words (char string[]);
	void read_line (char buffer[]);

	printf("Type in your text. \n");
	printf("When you are done, press 'RETURN'. \n\n");

	while ( ! end_of_text)
	{
		read_line (text);

		if ( text[0] == '\0' )
			end_of_text = 1;
		else
			total_words += count_words (text);

	}
	printf ("\nThere are %i words in the above text.\n", total_words);
}
 
