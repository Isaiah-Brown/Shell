/* A really simple shell facsimilie program! */

#include <stdio.h>
#include "command.h"

int loopShell()
{
	while (1)
	{
		printf("hacker@ltsp234:~/home/$ ");
		char c = getchar();

		while (c != '\n')
		{
			c = getchar();
			struct command_t command;
			command.make = make_command(&command, c);
			command.get = get_type(&command);
			command.make(c);
			char r = command.get(c);
			printf("Echoing the command: ");
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	loopShell();

	return 0;
}