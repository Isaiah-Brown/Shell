/* Isaiah's turtle shell */

#define _GNU_SOURCE 1 // for get_current_dir_name();
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CHANGE_DIRECTORY "cd"
#define EXIT "exit"
#define ENTER 
#define UNKOWN_COMMAND "\nlearn how to enter a linux command correctly, moron\n     (moron means 'stupid person' per GOOGLE) \n\n\n                  you are stupid\n" // YOU ARE STUPID!!!
#define UNKOWN_DIRECTORY "\nthat directory doesn't exist\nare you imaging things again?\n\n\nlike your girlfriend?\n"                                                  // YOU HAVE NO GIRLFREIND!!!
#define CHOO "CHOO"                                                                                                                                                    // FOR CHOO CHOO

void TRAIN() // FOR TRAIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    system("sl -F");
    system("sl -l");
    system("sl -a");
}

char *read_command(void) // to read user input into one string
{
    int bufsize = 16;
    char *buffer = malloc(sizeof(char) * bufsize); // make space for string
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

        if (pos >= bufsize) // increase memory space for string
        {
            bufsize *= 2;
            buffer = (char *)realloc(buffer, sizeof(char) * bufsize);
        }
    }
}

char **get_parameters(char *command) // to make a pointer to a pointer to the parameters of the command
{
    int buffsize = 4;
    char **parameters = malloc(buffsize * sizeof(char *)); // make space for array of pointers
    char *parameter = strtok(command, " ");
    int pos = 0;

    while (parameter != NULL) // loops to get all parameters
    {
        parameters[pos] = parameter;
        parameter = strtok(NULL, " "); // splits on " "
        pos++;

        if (pos >= buffsize) // increase memory space
        {
            buffsize *= 2;
            parameters = (char *)realloc(parameters, buffsize * sizeof(char *));
        }
    }
    free(parameter); //to free
    return parameters;
}

int run_shell() // running the actuall shell
{
    while (1)
    {
        char *cwd = get_current_dir_name(); // get the current directory so we can concatinate it to our hard-coded computer name
        printf("novak@shittycomputer:~%s ", cwd);
        char *command = read_command();              // get the command user entered
        char **parameters = get_parameters(command); // parse the commands so we can use execvp to run it

        if (!strcmp(parameters[0], EXIT)) // check if command is 'exit' if it is
        {
            free(command); //to free
            free(parameters); //to free
            free(cwd);
            exit(0);
        }
        
        if (!strcmp(parameters[0], CHANGE_DIRECTORY)) // check if command is 'cd' if it is it changes the directory while still in the parent
        {
            int x = chdir(parameters[1]);
            if (x != 0)
            {
                printf("%s", UNKOWN_DIRECTORY); // print error message
            }
        }
        else
        {
            if (fork() != 0) // clone the code
            {
                wait(); // wait for child to die
            }
            else // child
            {
                if ((strcmp(parameters[0], CHOO) == 0)) // FOR TRAIN!!!!
                {
                    TRAIN();
                }
                else
                {
                    int x = execvp(parameters[0], parameters); // execute the command
                    if (x != 0)
                    {
                        printf(UNKOWN_COMMAND); // error message
                    }
                }
            }
        }
        free(cwd);
        free(command); //to free
        free(parameters); // to free
    }
    return 0;
}

int main(int argc, char *argv[])
{
    printf("\n        Welcome to Isaiah's     \n\n"); // String to introduce the shell
    printf("_________---TURTLE SHELL---________\n\n\n");
    printf("Enter command <CHOO CHOO> for a surprise\n\n");
    run_shell(); // to run the shell
    return 0;
}
