#include "main.h"
/**
 * sigint_handler - ...
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nSimpleShell$ ", 14);
}
/*
 * print_env - ...
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/*
 * 
 * 
 */
char *_strtrim(char *str)
{
	char *start = str;
	char *end;

	while(*start == ' ' || *start == '\t' || *start == '\n' ||
			*start == '\r' || *start == '\v' || *start == '\f')
	{
		start++;
	}
	if (*start == 0)
	{
		*str = '\0';
		return str;
	}
	end = start + strlen(start) -1;
	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n' ||
				*end == '\r' || *end == '\v' || *end == '\f'))
	{	
		end--;
	}
	*(end + 1) = '\0';

	if (start != str)
	{
		memmove(str, start, end - start + 2);
	}
	return str;
}

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
        return NULL;
 
    token = strtok(path, ":");
    while (token != NULL)
    {
       
        len = strlen(token) + strlen(command) + 2;
        full_path = malloc(len);
        if (full_path == NULL)
        {
            free(path);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", token, command);

    
        if (access(full_path, X_OK) == 0)
        {
            free(path);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}

