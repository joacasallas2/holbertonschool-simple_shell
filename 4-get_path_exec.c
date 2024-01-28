#include "shell.h"
/**
 * get_path_exec - get the full path executable file
 * @command:  the input - first argument
 * @env: The environment variable
 * Return: A pointer to the executable file full path
 */
char *get_path_exec(char *command, char **env)
{
	int i = 0;
	struct stat st;
	char *full_path_command, *path, **path_directories;

	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (command);
			return (NULL);
		}
		i++;
	}
	path = get_path(env);
	if (path == NULL)
		return (NULL);
	path_directories = tokenizer(path, ":=");
	if (path_directories == NULL)
		return (NULL);
	full_path_command = malloc(sizeof(char *) * 1024);
	if (full_path_command == NULL)
	{
		free_array(path_directories);
		return (NULL);
	}
	while (path_directories[i])
	{
		snprintf(full_path_command,
				 strlen(path_directories[i]) + 2 + strlen(command),
				 "%s%s%s", path_directories[i], "/", command);
		if (stat(full_path_command, &st) == 0)
		{
			free_array(path_directories);
			return (full_path_command);
		}
		i++;
	}
	free_array(path_directories);
	free(full_path_command);
	return (NULL);
}
