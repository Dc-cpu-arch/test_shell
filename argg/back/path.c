#include "shell.h"

/**
 * path - gets the appropriate directory for a given command from stdout.
 * @line: command line input.
 * @args: possible arguments.
 * Return: the execution of the given command, otherwise -1.
 */
int path(char *line, char **args)
{
	char *copy, *tokens, *tmp, *command, *tmpp;
	char *path, *address;
	char tmp2[1] = "/";
	int i = 0;

	struct stat st;

	copy = _getenv("PATH", environ);
	printf("COPY: %s\n", copy);
	tmp = _strdup(line);
	address = _strdup(line);
	tokens = strtok(copy, "PATH=");
	tmpp = _strdup(tokens);
	tokens = strtok(tmpp, ":");
	command = strcat(tmp2, tmp);

	while (tokens)
	{
		path = _strcat(tokens, command);
		if (stat(path, &st) == 0)
		{
			free(address);
			address = NULL;
			address = _strdup(path);
			return (execve(address, args, NULL));
		}
		free(path);
		i++;
	}
	free(copy);
	copy = NULL;
	free(command);
	command = NULL;
	return (-1);
}

/**
 * _getenv - search for a given environment variable within environ.
 * @name: environment variable identifier.
 * @env: environ
 * Return: a pointer with the index of the wanted variable, otherwise Null.
 */
char *_getenv(const char *name, char **env)
{
	int i, j, check, l = 0;

	if (!env)
		return (NULL);
	while (name[l] != 0)
		l++;
	for (i = 0; env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
			if (env[i][j] == name[j])
				check++;
		if (check == l && env[i][check] == '=')
			return (env[i]);
	}
	return (NULL);
}
