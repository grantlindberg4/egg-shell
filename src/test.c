#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "command.h"
#include "path.h"

void testUserInput() {
    printf("Testing user input...\n");
    char* line = readline("esh>");
    int numArgs = 0;
    char** command = parseInput(line, &numArgs);

    if(strcmp(command[0], "exit") == 0) {
        printf("You have exited the program\n");
        exit(0);
    }

    for(int i = 0; i < numArgs; i++) {
        printf("%s\n", command[i]);
    }

    assert(strcmp(command[numArgs], "\0") == 0);
}

void testGetPaths() {
    printf("Testing getting paths...\n");
    char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);

    assert(paths != NULL);
    for(int i = 0; i < numPaths; i++) {
        printf("%s\n", paths[i]);
    }
}

void testSearchCurrentDirectory() {
    printf("Testing searching current directory...\n");
    char buffer[MAX_FILE_PATH_LENGTH];
    char* path = getcwd(buffer, sizeof(buffer));

    assert(path != NULL);
    assert(searchDirectory(path, "ls") == NULL);
    assert(searchDirectory(path, "background_test") != NULL);
}

void testFindCommand() {
    printf("Testing finding commands...\n");
    char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);

    assert(commandExistsInPath(paths, &numPaths, "ducks") == NULL);
    assert(commandExistsInPath(paths, &numPaths, "ls") != NULL);
    assert(commandExistsInPath(paths, &numPaths, "cat") != NULL);
    assert(commandExistsInPath(paths, &numPaths, "nc") != NULL);
}

void testExecuteProgram() {
    printf("Testing execv and fork...\n");
    char* line = readline("esh>");
    int numArgs = 0;
    char** command = parseInput(line, &numArgs);

    execute(command, numArgs);
}

int main() {
    testUserInput();
    testGetPaths();
    testSearchCurrentDirectory();
    testFindCommand();
    testExecuteProgram();

    return 0;
}
