#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>	//For getenv()

int main() {
    while(1) {
        char* line = readline("Enter a line: ");
        printf("%s\n", line);
	char * pathName = getenv("PATH");
	printf("PATH: %s\n", pathName);
    }
    return 0;
}
