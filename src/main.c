#define _BSD_SOURCE	//For lstat?

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>	//For getenv()
#include <string.h>	//For strtok()
#include <unistd.h>	//For getcwd(), lstat()
//#include <dirent.h>	//For readdir()
#include <sys/stat.h>	//For stat structure, lstat()
#include <sys/types.h>	//For lstat()

char ** getTokens(char * pathName) {
	printf("Path name: %s\n", pathName);
	char ** tokens = (char **)malloc(128 * sizeof(char *));
	int i = 0;
	tokens[i] = strtok(pathName, ":");
	while (i < 128) {
		tokens[i] = (char *)malloc(sizeof(char *));
		tokens[i] = strtok(NULL, ":");
		if (tokens[i] == NULL) break;
		printf("%s\n", tokens[i]);	//TODO
		i++;
	}
	return tokens;
}

int main() {

	char * pathName = getenv("PATH");
	char ** tokens = getTokens(pathName);
	char cwd[128];
	char * pathName2 = getcwd(cwd, 128);
	char ** tokens2 = getTokens(pathName2);
	//TODO Free stuff above.
	/*int i;
	for (i = 0; i < 128; i++) {
		if (tokens[i] == NULL) break;
		printf("%s\n", tokens[i]);
	}*/

	/*if (access(file_path, R_OK) ==0) {
		struct stat st;
		if (lstat(file_path, &st) == 0) {
			printf("%s\n", file_path);
		}
	}*/

	/*DIR * dir = NULL;

	if (access(file_path, R_OK)) {
		struct dirent * curr;
		while ((curr = readdir(dir)) != NULL) {
			char * file_name = curr->d_name;
			if (strcmp(curr->d_name, ".") != 0 && strcmp(curr->d_name, "..") != 0) {
				struct stat st;
				if (lstat(file_path, &st) == 0) {
					printf("%s\n", file_path);
				}
			}
		}
	}*/

    /*while(1) {
        *//*char* line = readline("Enter a line: ");
        printf("%s\n", line);*//*
    }*/
    return 0;
}
