#include "shell.h"
/**
 * _exec - fork the process to call execve system call
 * @commands: A pointer to the array of strings input
 * @env: A pointer to the array of environment variables
 *
 * Return: The pid parent process
 */
pid_t _exec(char **commands, char **env)
{
	pid_t parent_process, child_process;
	int status;
	char *path_exec;

	parent_process = getpid();
	/*Forks a child process using fork.*/
	child_process = fork();
	if (child_process == -1)
	{
		free_array(commands);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	/*In the child process*/
	if (child_process == 0)
	{
		/*it gets the full path of the executable file*/
		path_exec = get_path_exec(commands[0], env);
		if (path_exec == NULL)
		{
			free_array(commands);
			perror("./shell");
			exit(EXIT_SUCCESS);
		}
		/*it executes the given command using execve.*/
		if (execve(path_exec, commands, env) == -1)
		{
			free_array(commands);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	/*Waits for the child process.*/
	wait(&status);
	return (parent_process);
}
