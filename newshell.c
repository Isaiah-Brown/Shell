/* A really simple shell facsimilie program! */

#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *read_command_naive(void)
{
    int bufsize = 16;
    char *buffer = malloc(sizeof(char) * bufsize);
    int pos = 0;
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
            printf("buffer: %s\n", buffer);
            return buffer;
        }
        if (pos >= bufsize)
        {
            bufsize = bufsize * 2;
            buffer = (char *)realloc(buffer, sizeof(char) * bufsize);
        }
    }
}

int loopShell()
{

    while (1)
    {
        char* cwd = get_current_dir_name();
        printf("novak@shittycomputer:~%s ", cwd);
        char *command = read_command_naive();
        printf("The command you entered: %s \n", command);
        

        if(fork() != 0) {
            wait();
        }
        
        else 
        {
            //int s;
            //s = system(command);
            //int s = execve(command);
            //printf("%d", s);
            //exit(0);
        }

       
    }

    return 0;
}

int main(int argc, char *argv[])
{
    loopShell();
    return 0;
}

