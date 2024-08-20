#include "main.h"
/**
 * sigint_handler - ...
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nSimpleShell$ ", 14);
}

