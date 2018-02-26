#include <stdio.h>
#include <unistd.h>

int main(void) {
    while(1) {
        printf("Hello! I am the child!\n");
        sleep(5);
    }
    
    return 0;
}
