#include "main.h"

#define INITIAL_SIZE 10
#define CHUNK_SIZE 10

/**
 * tokenize_command - Tokenizes a string into an array of strings
 * @command: The string to tokenize
 * Return: A pointer to an array of pointers to tokens, or NULL on failure
 */
char **tokenize_command(char *command)
{
    size_t size = INITIAL_SIZE; 
    size_t i, position = 0;
    char **tokens;
    char *token;
    char *delimiters = " \t\n";
	char **new_tokens;

	tokens = malloc(size *sizeof(char *));
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
            new_tokens = malloc(size * sizeof(char *));
            if (!new_tokens)
            {
                perror("Error: Allocation failed");
                for (i = 0; i < position; i++)
                    free(tokens[i]);
                free(tokens);
                exit(EXIT_FAILURE);
            }
            for (i = 0; i < position; i++)
                new_tokens[i] = tokens[i];
            free(tokens);
            tokens = new_tokens;
        }
        tokens[position] = strdup(token);
        if (!tokens[position])
        {
            perror("Error: Allocation failed");
            for (i = 0; i < position; i++)
                free(tokens[i]);
            free(tokens);
            exit(EXIT_FAILURE);
        }
       	position++;
        token = strtok(NULL, delimiters);
    }
    tokens[position] = NULL;
    return tokens;
}

