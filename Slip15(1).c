/*
Slip NO 15
Q.1 
Write a C program to implement the shell. It should display the command
prompt “myshell$”. Tokenize the command line and execute the given
command by creating the child process. Additionally it should interpret the
following ‘list’ commands as
myshell$ list f dirname :- To print names of all the files in current directory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void list_files(const char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files in directory '%s':\n", dirname);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dp);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];

    while (1) {
        printf("myshell$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Tokenize the input
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARG_SIZE - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate the array

        // Check for the 'list' command
        if (i < 3 || strcmp(args[0], "list") != 0 || strcmp(args[1], "f") != 0) {
            printf("Invalid command. Use 'list f dirname'.\n");
            continue;
        }

        const char *dirname = args[2];

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) { // Child process
            list_files(dirname);
            exit(0); // Exit child process
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0); // Wait for the specific child process to finish
        }
    }

    return 0;
}