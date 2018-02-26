#include <readline/readline.h>
#include <readline/history.h>

#include "command.h"
#include "path.h"

int main() {
    char* pathList = getenv("PATH");
    int numPaths = 0;
    char** paths = getPaths(pathList, &numPaths);

    while(1) {
        char* line = readline("esh>");
        int numArgs = 0;
        char** command = parseInput(line, &numArgs);
        if(strcmp(command[0], "exit") == 0) {
            break;
        }

        char buffer[MAX_FILE_PATH_LENGTH];
        char* curr = getcwd(buffer, sizeof(buffer));
        char* path = NULL;
        if((path = commandExistsInPath(paths, &numPaths, command[0])) != NULL) {
            command[0] = path;
            execute(command, numArgs);
        }
        else if((path = searchDirectory(curr, command[0])) != NULL) {
            command[0] = path;
            execute(command, numArgs);
        }
        else {
            fprintf(stderr, "Unknown command: %s\n", command[0]);
        }
    }

    return 0;
}
