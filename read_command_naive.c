/* This is a naive implementation of the read_command() function
which is used in the shell program lecture notes
It doesn't expand the buffer (and it demonstrates why that is not good)
and it doesn't look for EOF (although I don't fully know how to fix that problem)
*/

#include <stdio.h>
#include <stdlib.h>

char *read_command_naive(void)
{
	int bufsize = 4;
	char *buffer = malloc(sizeof(char) * bufsize);
	int pos = 0;

	// Exemplifies the problem
	char *lesson_buffer = malloc(sizeof(char) * 1);
	lesson_buffer[0] = '5';
	// I don't assign this variable anywhere else

	while (1)
	{
		char c = getchar();
		if (c != '\n')
		{
			buffer[pos++] = c;
		}
		else
		{
			buffer[pos] = '\0'; // null byte

			// Confirm that these two things are both correct
			printf("buffer: %s\n", buffer);
			printf("lesson: %s\n", lesson_buffer);
			free(lesson_buffer);

			// Return the collected string
			return buffer;
		}
	}
}

int main()
{

	// If you try some really long input it should crash:
	// This is a really very long and verbose testing string.
	char *blah = read_command_naive();
	printf("Final Result: %s\n", blah);
}