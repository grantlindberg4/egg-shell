#include "path.h"

char** getPaths(char* pathList, int* i) {
    char** paths = (char**)malloc(MAX_PATHS*sizeof(char*));

    paths[*i] = strtok(pathList, ":");
    while (*i < MAX_PATHS) {
        paths[*i] = (char*)malloc(sizeof(char*));
        paths[*i] = strtok(NULL, ":");
        if (paths[*i] == NULL) {
            break;
        }
        *i += 1;
    }
    
    return paths;
}
