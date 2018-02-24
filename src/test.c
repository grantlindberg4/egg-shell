#include <readline/readline.h>
#include <readline/history.h>

#include "path.h"
#include "current_directory.h"

void test_user_input() {
    printf("Testing user input...\n");
    char* line = readline("esh>");
    printf("%s\n", line);
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
    searchCurrentDirectory(currentDirectoryPath);
}

int main() {
    test_user_input();
    test_get_paths();
    test_search_current_directory();

    return 0;
}
