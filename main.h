#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
#define MAX_ARGS 64
#define MAX_PATH 1024


int find_command(char *command, char *full_path, char **environ);
int _snprintf(char *str, size_t size, const char *format, ...);
char *_getenv(const char *name, char **environ);
int _strncmp(const char *s1, const char *s2, size_t n);
void display_prompt(void);
char *read_command(void);
void execute_command(char **command);
void free_memory(char **command);
char **tokenize_command(char *command);
void sigint_handler(int sig);
void print_env(void);
char *find_path(char *command);
char *_strtrim(char *str);

#endif /* MAIN_H */
