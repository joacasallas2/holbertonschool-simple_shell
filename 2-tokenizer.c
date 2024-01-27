#include "shell.h"
/**
 * tokenizer - function that splits a string and returns an array
 * of each word of the string
 * @line_ptr: The string to tokenizer
 * @delim: The characters to use as delim
 * Return: A pointer to the array of strings splitted
 */
char **tokenizer(char *line_ptr, char *delim)
{
	char *token;
	char **buffer;
	int i = 0, j = 0;

	/*Allocates memory*/
	buffer = malloc(sizeof(char *) * 1024);
	if (buffer == NULL)
	{
		return (NULL);
	}
	/* split the input line into tokens.*/
	token = strtok(line_ptr, delim);
	while (token != NULL)
	{
		/*Allocates memory for each token using strdup.*/
		buffer[i] = strdup(token);
		if (buffer[i] == NULL)
		{
			while (j < i)
			{
				free(buffer[j]);
				j++;
			}
			free(buffer);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}
