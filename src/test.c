#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <assert.h>

#include "path.h"
#include "current_directory.h"

void test_user_input() {
	while (true) {
	    printf("Testing user input...\n");
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
	assert(isInPath(paths, "ls") == true);	//TODO
	printf("Got past \"ls\" command!\n");
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

int main() {
    //test_user_input();

    /*char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);*/
	//assert(isInPath(paths, "ls") == true);

    test_get_paths();
    //test_search_current_directory();

    return 0;
}
