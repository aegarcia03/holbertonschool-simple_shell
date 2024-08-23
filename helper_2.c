#include "main.h"

/**
* sigint_handler - ...
* @sig: ...
*/
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nSimpleShell$ ", 14);
}
/**
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
/**
 * _strtrim - ...
 * @str: ...
 * Return: ...
 */
char *_strtrim(char *str)
{
	char *start = str;
	char *end;

	while (*start == ' ' || *start == '\t' || *start == '\n' ||
		*start == '\r' || *start == '\v' || *start == '\f')
	{
		start++;
	}
	if (*start == 0)
	{	*str = '\0';
		return (str);
	}
	end = start + strlen(start) - 1;
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
	return (str);
}
