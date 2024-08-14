### SIMPLE SHELL C

## Overview

## Ouput
The program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0] 

### Example
```c
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Allowed Functions and Systemn Call
* all functions from string.h
* "access", "chdir", "close", "closedir", "execve", "exit", "_exit, "fflush", "fork", "free", "getcwd", "getline" "getpid", "isatty", "kill", "malloc", "open", "opendir", "perror", printf, "fprintf", "vfprintf", "sprintf", "putchar", "read", "readdir", "signal", "stat", lstat, fstat, "strtok", "wait", "waitpid", "wait3", "wait4", "write"

## Compilation
To compile the shell, use the following command:
```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Usage
