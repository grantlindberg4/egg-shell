#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_PATHS 128

char** getPaths(char* pathList, int* i);

bool isInPath(char ** paths, char * cmd);

#endif
