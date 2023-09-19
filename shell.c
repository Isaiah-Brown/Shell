/* A really simple shell facsimilie program! */

#include <stdio.h>
#include "command.h"

char *appendChar(char command[], char c)
{
    char new[] = "";
    strcpy(new, command);
    int len = sizeof(command);
    new[len] = c;
    new[len + 1] = '\0';
    return new;

    // int len = strlen(command);

    // strcpy(new, command);
    // new[len + 1] = c;
}

int loopShell()
{

    while (1)
    {
        printf("hacker@ltsp234:~/home/$ ");
        char c = getchar();
        char command[] = c;

        while (c != '\n')
        {
            command[] = appendChar(command[], c);
            c = getchar();
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    // loopShell();
    char test[] = "test";
    printf("length: %d", sizeof(test));
    // printf("length: %d", strlen(test));
    return 0;
}