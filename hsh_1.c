#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *delimeter = "\t\n";
    while (1) {
        printf("SimpleShell$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            perror("Exiting shell");
            exit(1);
        }
 
        char *token;
        char **command = NULL;
        int i = 0;
        while ((token = strtok_r(line, delimeter, &line))) {
            command = realloc(command, (i + 1) * sizeof(char *));
            if (!command) {
                perror("Error: Memory allocation failed");
                exit(1);
            }
            command[i++] = token;
        }
        command[i] = NULL;
        pid_t child_pid = fork();
        if (child_pid == 0) {
            if (execvp(command[0], command) == -1) {
                perror("Could not execute");
                exit(1);
            }
        } else {
            wait(NULL);
        }
    }
    free(line);
    return 0;
}












