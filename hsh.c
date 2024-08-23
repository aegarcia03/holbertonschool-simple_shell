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


/*	if (strcmp(command[0], "exit") == 0)
	{
		free(command);
		exit_shell();
		free(tokens);
	}
*/

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
			_strtrim(command);

			tokens = tokenize_command(command);
			execute_command(tokens);
			free_memory(tokens);
			free(command);
		}
	}
	else
	{	while((command = read_command()) != NULL)
		{
			_strtrim(command);

			tokens = tokenize_command(command);
			execute_command(tokens);
			free_memory(tokens);
			free(command);
		}
	}
	return (0);
}
