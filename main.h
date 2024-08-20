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
#include <signal.h>

/*enviroment variable*/
extern char **environ;

/*helper functions*/

void display_prompt(void);
void _printf(char *prompt);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *read_command(void);
void execute_command(char **command);
void free_memory(char **command);
char **tokenize_command(char *command);
void sigint_handler(int sig);

#endif /* MAIN_H */
