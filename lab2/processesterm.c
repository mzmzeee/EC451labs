#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int child_status;
    pid_t pid;

    /* The argument list to pass to the “ls” command.  */
    char* arg_list[] = {
        "ls",     /* argv[0], the name of the program.  */
        "-l", 
        "/home/mzmzeee/Desktop/labs/lab1", 
        NULL      /* The argument list must end with a NULL.  */
    };

    /* Spawn a child process running the “ls” command.  */
    pid = fork();
    if (pid == 0) {
        // This is the child process.
        execvp(arg_list[0], arg_list);
        // If execvp returns, it must have failed.
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork failed.
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    /* Wait for the child process to complete.  */
    wait(&child_status);
    if (WIFEXITED(child_status)) {
        printf("The child process exited normally, with exit code %d\n",
               WEXITSTATUS(child_status));
    } else {
        printf("The child process exited abnormally\n");
    }

    return 0;
}