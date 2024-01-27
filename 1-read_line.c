#include "shell.h"
/**
 * read_line - Reads a line of input from the standard input using getline.
 *
 * Return: A pointer to the input string
 */
char *read_line(void)
{
	ssize_t readed;
	char *line_ptr = NULL;
	size_t n = 0;

	/*Reads from the standard input using getline.*/
	readed = getline(&line_ptr, &n, stdin);

	/*Handles end-of-file conditions or errors*/
	if (readed == -1)
	{
		free(line_ptr);
		if (feof(stdin))
		{
			if (isatty(0))
			{
				printf("\n");
			}
			exit(EXIT_SUCCESS);
		}
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	return (line_ptr);
}
