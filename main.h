#ifndef MAIN_H
#define MAIN_H

/*header files*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/*enviroment variable*/
extern char **environ;

/*helper functions*/

void display_prompt(void);
void _printf(char *prompt);

#endif /* MAIN_H */
