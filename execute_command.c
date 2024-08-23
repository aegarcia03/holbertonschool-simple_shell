#include "main.h"
/**
 * execute_command - ...
 */
void execute_command(char **command)
{
    pid_t child_pid;
    int status;
    char *full_path;

    if (command[0] == NULL)
        return;

  if (strcmp(command[0], "exit") == 0)
    {	
	    free(command);
	    exit_shell();
    }

	if (strcmp(command [0], "env") == 0){
	       	print_env();
	    	return;
  	}

    if (command[0][0] == '/' || command[0][0] == '.')
    {

        full_path = strdup(command[0]);
    }
    else
    {

        full_path = find_path(command[0]);
        if (full_path == NULL)
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", command[0]);
            return;
        }
    }

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error: Fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        if (execve(full_path, command, environ) == -1)
        {
            perror("Error: Command execution failed");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }

    free(full_path);

}

