/* A really simple shell facsimilie program! */

#include <stdio.h>
#include <stdlib.h>
#include "command.h"

char *read_command_naive(void)
{
    int bufsize = 4;
    char *buffer = malloc(sizeof(char) * bufsize);
    int pos = 0;

    // Exemplifies the problem
    // char *lesson_buffer = malloc(sizeof(char) * 1);
    // lesson_buffer[0] = '5';
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
            // printf("lesson: %s\n", lesson_buffer);
            // free(lesson_buffer);

            // Return the collected string
            return buffer;
        }
    }
}

char **get_parameters(char *command)
{
    char **parameters =
        for (int i = 0; i <)
}

int loopShell()
{

    while (1)
    {
        printf("hacker@ltsp234:~/home/$ ");
        char *command = read_command_naive();

        char **parameters = malloc(sizeof(char) * 4 * 4);
        int pos = 0;

        while (command[pos] != '\0')
        {

            pos++;
        }

        printf("The command you entered: %s \n", command);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    loopShell();
    return 0;
}