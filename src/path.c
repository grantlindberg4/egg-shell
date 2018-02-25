#include "path.h"
#include "current_directory.h"
#include <assert.h>

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

/*TODO Iterate through pathList*/
char* isInPath(char ** paths, char * cmd) {
	assert(paths != NULL);
	int i = 0;
	while (i < MAX_PATHS) {
		if(paths[i] == NULL)
			break;
        char* str = NULL;
		if((str = searchCurrentDirectory(paths[i], cmd)) != NULL)
			return str;
		i++;
	}
	return NULL;
}
