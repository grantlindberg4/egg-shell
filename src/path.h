#ifndef PATH_H
#define PATH_H

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

#define MAX_PATHS 128
#define MAX_FILE_PATH_LENGTH 4096

bool directoryIsAccessible(char* dirName);
char* searchDirectory(char* currentFilePath, char* command);
char** getPaths(char* pathList, int* i);
char* commandExistsInPath(char** paths, int* numPaths, char* command);

#endif
