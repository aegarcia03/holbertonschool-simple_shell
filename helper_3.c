#include "main.h"
/**
* find_path - Find the full path of a command
* @command: The command to find
*
* Return: The full path of the command if found, or NULL if not found
*/
char *find_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *token;
	char *full_path;
	size_t len;

	if (path == NULL)
	return (NULL);

	token = strtok(path, ":");
	while (token != NULL)
	{

	len = strlen(token) + strlen(command) + 2;
	full_path = malloc(len);

	if (full_path == NULL)
	{
		free(path);
		return (NULL);
	}

	snprintf(full_path, len, "%s/%s", token, command);

	if (access(full_path, X_OK) == 0)
	{
		free(path);
		return (full_path);
	}

	free(full_path);
	token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
/**
* exit_shell - ...
*
*/
void exit_shell(void)
{
	exit(0);
}
