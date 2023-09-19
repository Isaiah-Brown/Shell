/* read_user_input.c */

#include <stdio.h>

/* Simple program that demonstrates how to read user input in c */

int main(int argc, char *argv[]){

	printf("Type a letter you jerk!: ");

	int in;
	char character;
	
	in = getchar();
	character = (char)in;

	printf("You typed: %c\n", character);

}


