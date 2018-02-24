#include "current_directory.h"

bool directoryIsAccessible(char* dirName) {
    return dirName[0] != '.' && strcmp(dirName, ".") != 0 && strcmp(dirName, "..") != 0;
}

void searchCurrentDirectory(char* currentFilePath) {
    DIR* dir = opendir(currentFilePath);
    if(dir == NULL) {
        return;
    }
    printf("%s\n", currentFilePath);
    struct dirent* curr;
    while((curr = readdir(dir)) != NULL) {
        if(curr->d_type != DT_DIR) {
            continue;
        }
        else if(curr->d_type == DT_DIR && directoryIsAccessible(curr->d_name)) {
            char* newFilePath = malloc(strlen(currentFilePath) + strlen(curr->d_name) + 2);
            sprintf(newFilePath, "%s/%s", currentFilePath, curr->d_name);
            searchCurrentDirectory(newFilePath);
            free(newFilePath);
        }
    }
    closedir(dir);
}
