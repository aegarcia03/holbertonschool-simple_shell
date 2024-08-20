#include "main.h"
/**
 * main - run commands with their full path
 *
 * Return: ...
 */
int main(void)
{
	char *line;
	char **command;

	while (1)
	{
		display_prompt();
		line = read_command();
		command = tokenize_command(line);

		if (command[0] == NULL)
		{
			free(line);
			free(command);
			continue;
		}
		execute_command(command);

		free_memory(command);
		free(line);
	}
	return (0);
}
