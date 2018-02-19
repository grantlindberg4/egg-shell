#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    while(1) {
        char* line = readline("Enter a line: ");
        printf("%s\n", line);
    }
    return 0;
}
