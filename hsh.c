#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	char *token;
	char **command = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *delimeter = "\t\n";
    int i;
    
    	while (1) {
        printf("SimpleShell$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            perror("Exiting shell");
            exit(1);
        }

        i = 0;
        
	while ((token = strtok(line, delimeter))) {
            command = malloc(sizeof(char *) * 1024);
            if (!command) {
                perror("Error: Memory allocation failed");
                exit(1);
            }
            command[i++] = token;
        }
        command[i] = NULL;
        child_pid = fork();
        if (child_pid == 0) {
            if (execve(command[0], command, NULL) == -1) {
                perror("Could not execute");
                exit(1);
            }
        } else {
            wait(NULL);
        }
    }
	free(command);
	free(line);
	return 0;
}












