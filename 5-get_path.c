#include "shell.h"
/**
 * get_path - function that get the path variable
 * @env: A pointer to the array of environment variables
 *
 * Return: A pointer to the PATH environment
 */
char *get_path(char **env)
{
	int i = 0;
	char *env_copy, *token;

	while (env[i] != NULL)
	{
		env_copy = strdup(env[i]);
		if (env_copy == NULL)
		{
			return (NULL);
		}
		token = strtok(env_copy, "=");
		if (strcmp(token, "PATH") == 0)
		{
			free(env_copy);
			return (env[i]);
		}
		free(env_copy);
		i++;
	}
	return (NULL);
}
