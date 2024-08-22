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
	const char* pathEnv;
	
	pathEnv = getenv("PATH");
	if (!pathEnv)
	{
		printf("PATH environment variable not found.\n");
		exit(1);
	}

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
