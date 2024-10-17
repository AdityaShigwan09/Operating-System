/*
Slip No 3
Q.2 Write a programto implement the toy shell. It should display the command
prompt “myshell$”. Tokenize the command line and execute the given
command by creating the child process. Additionally it should interpret the
following commands.
count c filename :- To print number of characters in the file.
count w filename :- To print number of words in the file.
count l filename :- To print number of lines in the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void count_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    
    printf("Number of characters in file '%s': %ld\n", filename, size);
}

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return;
    }

    int count = 0;
    char word[MAX_INPUT_SIZE];
    
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }
    fclose(file);

    printf("Number of words in file '%s': %d\n", filename, count);
}

void count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return;
    }

    int count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(file);

    printf("Number of lines in file '%s': %d\n", filename, count);
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

        // Check for the command
        if (i < 3 || strcmp(args[0], "count") != 0) {
            printf("Invalid command. Use 'count c filename', 'count w filename', or 'count l filename'.\n");
            continue;
        }

        const char *command = args[1];
        const char *filename = args[2];

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) { // Child process
            if (strcmp(command, "c") == 0) {
                count_characters(filename);
            } else if (strcmp(command, "w") == 0) {
                count_words(filename);
            } else if (strcmp(command, "l") == 0) {
                count_lines(filename);
            } else {
                printf("Invalid command option. Use 'c', 'w', or 'l'.\n");
            }
            exit(0); // Exit child process
        } else { // Parent process
            wait(NULL); // Wait for child process to finish
        }
    }

    return 0;
}