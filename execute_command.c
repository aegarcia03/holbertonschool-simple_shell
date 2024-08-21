#include "main.h"
/**
 * execute_command - ...
 * ...
 *
 */
void execute_command(char **command)
{
    pid_t child_pid;
    int status;

    if (command == NULL || command[0] == NULL)
    {
        fprintf(stderr, "Error: Command is NULL or empty\n");
        return;
    }

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error child_pid");
        exit(1);
    }

    if (child_pid == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror("Error: Command not found");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}

