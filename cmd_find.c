#include "main.h"

/**
 * find_command - Search for the command in PATH
 * @command: The command to search for
 * @full_path: Buffer to store the full path if found
 * @environ: Environment variables
 *
 * Return: 1 if found, 0 if not found
 */
int find_command(char *command, char *full_path, char **environ)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *dir = NULL;
	int found = 0;

	path = _getenv("PATH", environ);
	if (!path)
		return (0);
	path_copy = _strdup(path);
	if (!path_copy)
		return (0);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		_snprintf(full_path, MAX_PATH, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (found);
}
