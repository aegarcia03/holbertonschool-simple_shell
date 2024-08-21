#include "main.h"
/**
 * display_prompt - ...
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "SimpleShell$ ", 13);
}
/*
 * read_command- ...
 *
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	
	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		exit(0);
	}
	return (line);
}
/**
 * tokenize_command- ..
 *
 * Return: ...
 *
char **tokenize_command(char *command)
{
	char **tokens = malloc(sizeof(char *) * 1024);
	char *token;
	int i = 0;
	char *delimeters = " \t\n";

	if(!tokens)
	{
		perror("Error: Allocation failed");
		exit(1);
	}
	token = strtok(command, delimeters);
	
	i = 0;

	while (token != NULL)
	{
		tokens[i] = strdup(token);

		if (!tokens[i])
		{
			perror("Error: Allocation failed");
			exit(1);
		}
		i++;
		token = strtok(NULL, delimeters);

	}
	tokens[i] = NULL;

	return(tokens);
}
 * execute_command - fork a child process to execute command
 *
 */
void execute_command(char **command)
{
	pid_t child_pid;
	int status;

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
/**
 * free_memory - free any dynamically allocated memory
 */
void free_memory(char **command)
{
	int i = 0;

	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(command);
}

