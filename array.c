#include <stdio.h>
#include <stdlib.h>


int main() {

    char command[] = "cd please your for";

    //char examples[][10] = {"kyle", "bob", "elise"};

    //char name[0];

    char names[0][10];

    int char_pos = -1;
    int word_pos = 0;

    //printf("%c", command[0]);


    while(command[char_pos] != '\0'){
        char_pos++;
        while(command[char_pos] != ' ') {
            names[word_pos][char_pos] = command[char_pos];
            char_pos++;
        }
        word_pos++;
    }

    printf("%c", names[0][1]);
    //char_pos = 0;
    word_pos = 0;
    
    char *word;
    word = (char*) malloc(10 * sizeof(char));
    //char word[] = names[word_pos];
    while(word[0] != '\0') {
        printf("%s", word);
        word_pos++;
        word = names[word_pos];
    }


    return 0;
}