#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "command.h"

char** parseInput(char* line, int* numArgs) {
    char** command = NULL;
    char* arg = strtok(line, " ");
    while(arg != NULL) {
        *numArgs += 1;
        command = realloc(command, *numArgs*sizeof(char*));
        if(command == NULL) {
            fprintf(stderr, "Failed to realloc for command\n");
            exit(-1);
        }

        command[*numArgs-1] = arg;

        arg = strtok(NULL, " ");
    }

    command = realloc(command, (*numArgs+1)*sizeof(char*));
    command[*numArgs] = NULL;

    return command;
}

void execute(char** command, int numArgs) {
    assert(command[numArgs] == NULL);
    int status;

    bool runInBackground = false;
    if(strcmp(command[numArgs-1], "&") == 0) {
        printf("Run in back\n");
        runInBackground = true;
    }

    if(fork() == 0) {
        execv(command[0], command);
        fprintf(stderr, "Failed to exec %s\n", command[0]);
    }
    else if(!runInBackground) {
        wait(&status);
    }
}
