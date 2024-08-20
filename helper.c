#include "main.h"

/**
 * _printf - ...
 */
void _printf(char *prompt)
{
	write(STDOUT_FILENO, prompt, strlen(prompt));
}
/**
 * display_prompt - ...
 */

void display_prompt(void)
{
	_printf("SimpleShell$ ");
}
