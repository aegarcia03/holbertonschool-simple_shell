#include "main.h"
/**
 * main - run commands with their full path
 *
 * Return: ...
 */
int main(void)
{
	char **tokens;
	char *command;

	signal(SIGINT, sigint_handler);

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			display_prompt();
			command = read_command();
			if (command == NULL)
			{
				free(command);
				break;
			}
			tokens = tokenize_command(command);
			execute_command(tokens);
			free_memory(tokens);
			free(command);
		}
	}
	else
	{	while((command = read_command()) != NULL)
		{
			tokens = tokenize_command(command);
			execute_command(tokens);
			free_memory(tokens);
			free(command);
		}
	}
	return (0);
}
