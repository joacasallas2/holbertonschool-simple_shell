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
	int i = 0, flag = 1;

	/*Reads from the standard input using getline.*/
	readed = getline(&line_ptr, &n, stdin);
	if (line_ptr[0] == 32)
	{
		flag = 0;
		while (line_ptr[i] == 32)
		{
			i++;
			if (line_ptr[i] != 32 && line_ptr[i] != 10)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		free(line_ptr);
		return (NULL);
	}
	/*Handles end-of-file conditions or errors*/
	if (readed == -1)
	{
		free(line_ptr);
		if (feof(stdin))
		{
			if (isatty(0))
				printf("\n");
			exit(EXIT_SUCCESS);
		}
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	return (line_ptr);
}
