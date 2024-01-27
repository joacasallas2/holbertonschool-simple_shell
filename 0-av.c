#include "shell.h"
/**
 * print_av -  function that prints all the arguments, without using ac
 * @ac: number of args
 * @av: A pointer to the array of args
 * Return: Always 0
 */
int print_av(int ac, char *av[])
{
	int i = 0;
	(void)ac;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
