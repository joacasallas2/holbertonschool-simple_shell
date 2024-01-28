#include "shell.h"
/**
 * main - Program that prints "$ ", wait for the user to enter a command
 * and then execute
 * @ac: The number of arguments from input
 * @av: A pointer to the array of strings input
 * @env: A pointer to the array of environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char *line_ptr, **commands;

	(void)ac;
	(void)av;
	/*runs an infinite loop to keep the shell active.*/
	while (1)
	{
		/*Prints (#cisfun$ ) if the input is from a terminal.*/
		if (isatty(0))
		{
			printf("#cisfun$ ");
		}
		/*Reads input and store in line_ptr*/
		line_ptr = read_line();
		if (line_ptr == NULL)
		{
			continue;
		}
		/*Tokenizes the input and store in commands*/
		commands = tokenizer(line_ptr, " \n");
		free(line_ptr);
		if (strcmp(commands[0], "exit") == 0)
		{
			free_array(commands);
			exit(EXIT_SUCCESS);
		}
		/*Executes the commands*/
		_exec(commands, env);
		free_array(commands);
	}
	return (0);
}
