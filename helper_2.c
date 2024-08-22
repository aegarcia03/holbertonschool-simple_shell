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
