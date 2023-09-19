/* A really simple shell facsimilie program! */

#include <stdio.h>

int main(int argc, char *argv[]){
	while(1){
		printf("hacker@ltsp234:~/home/$ ");
		char c = getchar();
		while(c != '\n'){
			c = getchar();
		}
	}

	return 0;
}