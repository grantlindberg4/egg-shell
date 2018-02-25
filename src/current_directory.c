#include "current_directory.h"

bool directoryIsAccessible(char* dirName) {
    return dirName[0] != '.' && strcmp(dirName, ".") != 0 && strcmp(dirName, "..") != 0;
}

char* searchCurrentDirectory(char* currentFilePath, char* cmd) {
    DIR* dir = opendir(currentFilePath);
    if(dir == NULL) {
        return NULL;
    }
    // printf("%s\n", currentFilePath);
    struct dirent* curr;
    while((curr = readdir(dir)) != NULL) {
        if(curr->d_type != DT_DIR) {
            if (strcmp(curr->d_name, cmd) == 0)
                return currentFilePath;
            }
        else if(curr->d_type == DT_DIR && directoryIsAccessible(curr->d_name)) {
            char* newFilePath = malloc(strlen(currentFilePath) + strlen(curr->d_name) + 2);
            sprintf(newFilePath, "%s/%s", currentFilePath, curr->d_name);
            char* answer = searchCurrentDirectory(newFilePath, cmd);
            free(newFilePath);
            return answer;
        }
    }
    closedir(dir);

    return NULL;
}
