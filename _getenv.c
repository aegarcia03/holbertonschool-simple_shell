#include "main.h"
/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 * @environ: Environment variables
 *
 * Return: Pointer to the value of the environment variable, or NULL not found
 */
char *_getenv(const char *name, char **environ)
{
	int i;
	size_t name_len;

	if (!name || !environ)
		return (NULL);
	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0
				&& environ[i][name_len] == '=')
			return (&environ[i][name_len + 1]);
	}
	return (NULL);
}
