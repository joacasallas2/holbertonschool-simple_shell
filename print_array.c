#include "shell.h"
/**
 * print_array - Function that prints an array of strings
 * @array: The pointer to the array
 * Return: Nothing
 */
void print_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
