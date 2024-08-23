#include "main.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "SimpleShell$ ", 13);
}

/**
 * read_command - Reads a command
 *
 * Return: A string with the command
 * NULL if an error occurs.
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
		return (NULL);
	}
	_strtrim(line);

	return (line);
}

/**
 * free_memory - free any dynamically allocated memory
 * @command: A pointer to an array of strings to be freed.
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
