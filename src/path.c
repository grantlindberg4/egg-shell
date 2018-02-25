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

/*TODO Iterate through pathList
bool isInPath(char * pathList, char * cmd) {
	assert(pathList != NULL);
	int i = 0;
	while (i < MAX_PATHS) {
		if (strcmp(pathList[i], cmd) == 0)
			return true;
		if (pathList[i] == NULL)
			break;
	}
	return false;
}*/
