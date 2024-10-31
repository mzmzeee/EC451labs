#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char process_name[256];

    printf("Enter the process name to send SIGUSR1 signal: ");
    scanf("%s", process_name);

    for(int i = 0; i < 10; i++) {
        char command[512];
        snprintf(command, sizeof(command), "pkill -SIGUSR1 %s", process_name);
        system(command);
        printf("Signal sent to %s: %d\n", process_name, i+1);
        sleep(2); 
    }
    return 0;
}