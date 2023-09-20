/* A really simple shell facsimilie program! */

#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
            bufsize *= 2;
            buffer = (char *)realloc(buffer, sizeof(char) * bufsize);
        }
    }
}

char **get_parameters(char* command) 
{
    int buffsize = 4;
    char **parameters = malloc(buffsize * sizeof(char*));
    
    char *parameter = strtok(command, " ");
    int pos = 0;

    while(parameter != NULL) 
    {
        parameters[pos] = parameter;
        parameter = strtok(NULL, " ");
        pos++;

        if (pos >= buffsize) 
        {
            buffsize *= 2;
            parameters = (char *) realloc(parameters, buffsize * sizeof(char*));
        }
    }

    return parameters;
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
            char **parameters = get_parameters(command);
            int pos = 0;
            while (parameters[pos] != NULL) 
            {
                printf("%s\n", parameters[pos]);
                pos++;
            }
            printf("got parameters\n");
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

