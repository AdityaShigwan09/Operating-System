/*
Slip No 21
Q.1 
Write a C Program to create a child process using fork (), display parent and
child process id. Child process will display the message “I am Child Process”
and the parent process should display “I am Parent Process”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("I am Child Process with PID: %d\n", getpid());
    } else {
        // Parent process
        printf("I am Parent Process with PID: %d and my child's PID is: %d\n", getpid(), pid);
    }

    return 0;
}