#ifndef CURRENT_DIRECTORY_H
#define CURRENT_DIRECTORY_H

#define _BSD_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILE_PATH_LENGTH 4096

bool directoryIsAccessible(char* dirName);
bool searchCurrentDirectory(char* currentFilePath, char * cmd);

#endif
