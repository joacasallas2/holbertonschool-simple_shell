#include "shell.h"
/**
 * free_array - free an array
 * @array: A pointer to the array to free
 *
 * Return: Nothing
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
