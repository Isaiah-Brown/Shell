#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




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

int main(int argc, char *argv[]) {
    
    char* command = read_command();
    if(command[0] == '\0') {
        printf("yurrr");
    }
    printf("This is the command: %s\n\n", command);
    return 0;
}