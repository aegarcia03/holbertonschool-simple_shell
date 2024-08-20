#include "main.h"
/*
 * _strlen - ..
 * Return: ..
 */
int _strlen(char *s)
{
	int len = 0;
	
	while(s[len])
		len++;
	return(len);
}
/**
 * _strcpy - ..
 * @dest: ..
 * @src: ...
 *
 * Return: ...
 */
char* _strcpy(char *dest, char*src)
{
	int i = 0;
	
	while (src[i])
	{
		dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
	return(dest);
}
/**
 * _strcat - ...
 * @dest: ..
 * @src: ...
 *
 * Return: ...
 */
char* _strcat(char *dest, char *src)
{	
	int dest_len = _strlen(dest);
	int i = 0;

	while(src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return(dest);
}
/**
 * _printf - ...
 */
void _printf(char *prompt)
{
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
/**
 * display_prompt - ...
 */

void display_prompt(void)
{
	_printf("SimpleShell$ ");
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
		perror("EXITING SHELL");
		exit(1);
	}
	return (line);
}
/**
 * tokenize_command- ..
 *
 * Return: ...
 */
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
		token = strtok(NULL, delimeters);
		i++;

	}
	tokens[i] = NULL;

	return(tokens);
}
/**
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

