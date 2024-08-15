# SIMPLE SHELL C

## Overview
This project is an implementation of a basic UNIX command line interpreter that is aimed to replicate the functionality of /bin/sh.
The program provides support for both interactive and non-interactive modes, carries out commands, and manages errors in a manner that is compatible with the shell program.

## Ouput
The program's output must exactly match /bin/sh, except for error messages, where the program name should be replaced with the executable's actual name, usually ./hsh.

## Features
* Interactive Mode: Prompts the user for input, executes commands, and displays the prompt again after execution.
* Non-Interactive Mode: Reads commands from a file or standard input, executes them, and exits after execution.
* Error Handling: When an executable cannot be found, an error message is printed. The error output follows the format of /bin/sh, with the program's name dynamically replaced by the actual name of the shell.
* End of File (Ctrl+D): Properly handles the EOF condition.


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
## Testing
### Interactive mode
```c
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### Non-interactive
```c
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Tasks
* Task 0: Write the README.md, man page, and AUTHORS file.
* Task 1: Ensure that all code passes the Betty style checks.
* Task 2: Implement the basic shell behavior without handling command arguments.
* Task 3: Extend the shell to handle commands with arguments.
* Task 4: Implement PATH handling, ensuring that fork() is not called if the command doesn’t exist.
* Task 5: Implement the exit built-in.
* Task 6: Implement the env built-in to print the current environment.

## Authors

Angela Enriquez Garcia, Phon Soumpholphakdy,
