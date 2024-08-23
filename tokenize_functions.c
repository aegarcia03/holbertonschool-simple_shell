#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define CHUNK_SIZE 10

/**
 * allocate_tokens - Allocates memory for the tokens array
 * @size: The size of the array to allocate
 * @tokens: The original tokens array to copy
 * @position: The current position in the tokens array
 * Return: A pointer to the newly allocated array, or NULL on failure
 */
char **allocate_tokens(size_t size, char **tokens, size_t position)
{
    char **new_tokens = malloc(size * sizeof(char *));
    size_t i;

    if (new_tokens)
    {
        for (i = 0; i < position; i++)
            new_tokens[i] = tokens[i];
        free(tokens);
    }
    return new_tokens;
}

/**
 * handle_allocation_failure - Handles memory allocation failure
 * @tokens: The tokens array to free
 * @position: The current position in the tokens array
 */
void handle_allocation_failure(char **tokens, size_t position)
{
	size_t i;
    
	for (i = 0; i < position; i++)
		free(tokens[i]);
    
	free(tokens);
    perror("Error: Allocation failed");
    exit(EXIT_FAILURE);
}

/**
 * tokenize_command - Tokenizes a string into an array of strings
 * @command: The string to tokenize
 * Return: A pointer to an array of pointers to tokens, or NULL on failure
 */
char **tokenize_command(char *command)
{
    size_t size = INITIAL_SIZE; 
    size_t position = 0;
    char **tokens;
    char *token;
    char *delimiters = " \t\n";
    char **new_tokens;

    tokens = malloc(size * sizeof(char *));
    if (!tokens)
    {
        perror("Error: Allocation failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, delimiters);
    while (token != NULL)
    {
        if (position >= size)
        {
            size += CHUNK_SIZE;

	    new_tokens = allocate_tokens(size, tokens, position);

            if (!new_tokens)
                handle_allocation_failure(tokens, position);
            tokens = new_tokens;
        }

        tokens[position] = strdup(token);
        if (!tokens[position])
            handle_allocation_failure(tokens, position);

        position++;
        token = strtok(NULL, delimiters);
    }

    tokens[position] = NULL;
    return tokens;
}
