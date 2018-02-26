#ifndef COMMAND_H
#define COMMAND_H

char** parseInput(char* line, int* numArgs);
void execute(char** command, int numArgs);

#endif
