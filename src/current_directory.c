#include "current_directory.h"

bool directoryIsAccessible(char* dirName) {
    return dirName[0] != '.' && strcmp(dirName, ".") != 0 && strcmp(dirName, "..") != 0;
}

bool searchCurrentDirectory(char* currentFilePath, char * cmd) {
	bool isFound = false;
    DIR* dir = opendir(currentFilePath);
    if(dir == NULL) {
        return false;
    }
    printf("%s\n", currentFilePath);
    struct dirent* curr;
    while((curr = readdir(dir)) != NULL) {
        if(curr->d_type != DT_DIR) {
		if (strcmp(curr->d_name, cmd) == 0)
			isFound = true;
            continue;
        }
        else if(curr->d_type == DT_DIR && directoryIsAccessible(curr->d_name)) {
            char* newFilePath = malloc(strlen(currentFilePath) + strlen(curr->d_name) + 2);
            sprintf(newFilePath, "%s/%s", currentFilePath, curr->d_name);
            isFound = searchCurrentDirectory(newFilePath, cmd);
            free(newFilePath);
        }
    }
    closedir(dir);
	return isFound;
}
