#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "path.h"
#include "current_directory.h"

void test_user_input() {
    printf("Testing user input...\n");
	while (true) {
	    char* line = readline("esh>");
	    printf("%s\n", line);

		if (strncmp("exit", line, strlen("exit") - 1) == 0)
			exit(0);
	}
}

void test_get_paths() {
    printf("Testing getting paths...\n");
    char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);
    for(int i = 0; i < numPaths; i++) {
        printf("%s\n", paths[i]);
    }
}

void test_search_current_directory() {
    printf("Testing searching current directory...\n");
    char buffer[MAX_FILE_PATH_LENGTH];
    char* currentDirectoryPath = getcwd(buffer, sizeof(buffer));
    if(currentDirectoryPath == NULL) {
        fprintf(stderr, "Error trying to get current directory");
    }
    searchCurrentDirectory(currentDirectoryPath, "ls");	//TODO
}

void test_find_command() {
    printf("Testing finding commands...\n");
    char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);
	assert(isInPath(paths, "ducks") == NULL);	//TODO
	assert(isInPath(paths, "ls") != NULL);	//TODO
	assert(isInPath(paths, "cat") != NULL);	//TODO
	assert(isInPath(paths, "nc") != NULL);	//TODO
}

void test_execute_program() {
    printf("Testing execv and fork...\n");
    int status;
    char* args[2];
    args[0] = "/bin/ls";
    args[1] = "-l";
    args[2] = NULL;
    // args[0] = "ducks";
    // args[1] = NULL;

    if(fork() == 0) {
        execv(args[0], args);
        fprintf(stderr, "Failed to exec\n");
    }
    else {
        wait(&status);
    }
}

void test_parse_commands() {
    printf("Testing parsing user input...\n");
    char* line = readline("esh>");

    char** args = NULL;
    int i = 0;
    char* next = strtok(line, " ");
    while(next != NULL) {
        i++;
        args = realloc(args, i*sizeof(char*));
        if(args == NULL) {
            exit(-1);
        }

        args[i-1] = next;

        next = strtok(NULL, " ");
    }

    args = realloc(args, (i+1)*sizeof(char*));
    args[i] = "\0";

    for(int j = 0; j < i; j++) {
        printf("%s\n", args[j]);
    }
    assert(strcmp(args[i], "\0") == 0);
}

int main() {
    // test_user_input();
    // test_get_paths();
    // test_find_command();
    //test_search_current_directory();
    // test_execute_program();
    test_parse_commands();

    return 0;
}
