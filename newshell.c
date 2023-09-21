/* Isaiah's turtle shell */

#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CHANGE_DIRECTORY "cd"
#define UNKOWN_COMMAND "\nlearn how to enter a linux command correctly, moron\n     (moron means 'stupid person' per GOOGLE) \n\n\n                  you are stupid\n"
#define UNKOWN_DIRECTORY "\nthat directory doesn't exist\nare you imaging things again?\n\n\nlike your girlfriend?\n"
#define CHOO "CHOO"

void TRAIN()
{
    //char** one = {"sl", "sl"};
    //int x = execvp(one[0], one);
    //printf("%d", x);


    /*
    int x = execvp("sl", "sl -l");
    printf("%d", x);
    int x = execvp("sl", "sl -a");
    printf("%d", x);
    */
   system("sl -F");
   system("sl -l");
   system("sl -a");
}

char *read_command(void)
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

int run_shell()
{
    while (1)
    {
        char* cwd = get_current_dir_name();
        printf("novak@shittycomputer:~%s ", cwd);
        char *command = read_command();
        char **parameters = get_parameters(command);
  
        if(!strcmp(parameters[0], CHANGE_DIRECTORY))
        {
            int x = chdir(parameters[1]);
            if (x != 0) 
            {
                printf("%s", UNKOWN_DIRECTORY);
            }
        }
        else 
        {
            if(fork() != 0) 
            {
                wait();
            }
            else 
            {
                if((strcmp(parameters[0], CHOO) == 0))
                {
                    TRAIN();  
                }
                else
                {
                    int x = execvp(parameters[0], parameters);
                    if (x != 0) 
                    {
                        printf(UNKOWN_COMMAND);
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    printf("\n        Welcome to Isaiah's     \n\n");
    printf("_________---TURTLE SHELL---________\n\n\n");
    printf("Enter command <CHOO CHOO> for a surprise\n\n");
    run_shell();
    return 0;
}

