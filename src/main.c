#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>	//For getenv()
#include <string.h>	//For strtok()

int main() {
	char * pathName = getenv("PATH");
	printf("PATH: %s\n", pathName);
	char ** tokens = (char **)malloc(128 * sizeof(char *));
	int i = 0;
	tokens[i] = strtok(pathName, ":");
	while (i < 128) {
		tokens[i] = (char *)malloc(sizeof(char *));
		tokens[i] = strtok(NULL, ":");
		if (tokens[i] == NULL) break;
		printf("%s\n", tokens[i]);
		i++;
	}

    /*while(1) {
        *//*char* line = readline("Enter a line: ");
        printf("%s\n", line);*//*
    }*/
    return 0;
}
