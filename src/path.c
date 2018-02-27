#define _BSD_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>

#include "path.h"

bool directoryIsAccessible(char* dirName) {
    return dirName[0] != '.' && strcmp(dirName, ".") != 0 && strcmp(dirName, "..") != 0;
}

char* searchDirectory(char* currentFilePath, char* command) {
    DIR* dir = opendir(currentFilePath);
    if(dir == NULL) {
        return NULL;
    }
    struct dirent* curr;
    while((curr = readdir(dir)) != NULL) {
        if(curr->d_type != DT_DIR) {
            if(strcmp(curr->d_name, command) == 0) {
                char* pathToCommand = malloc(strlen(currentFilePath) + strlen(curr->d_name) + 2);
                sprintf(pathToCommand, "%s/%s", currentFilePath, curr->d_name);
                
                return pathToCommand;
            }
        }
    }
    closedir(dir);

    return NULL;
}

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

char* commandExistsInPath(char** paths, int* numPaths, char* command) {
    assert(paths != NULL);
    for(int i = 0; i < *numPaths; i++) {
        char* received = NULL;
        if((received = searchDirectory(paths[i], command)) != NULL) {
            return received;
        }
    }
    
    return NULL;
}
