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
	char *path, *address, *test;
	char tmp2[1] = "/";
	int i = 0, j = 1, h = 0;
	char *list[1024];

	struct stat st;

	copy = _getenv("PATH", environ);
	tmp = _strdup(line);
	address = _strdup(line);
	tokens = strtok(copy, "PATH=");
	tmpp = _strdup(tokens);
	list[0] = strtok(tmpp, ":");

	while (tmpp != NULL)
		{
			list[j] = strtok(NULL, ":");
			j++;
		}
	command = _strcat(tmp2, tmp);
	printf("asd");

	while (list[j])
	{
		printf("PATH IS %s\n", path);
		path = _strcat(list[j], command);
		printf("PATH IS %s\n", path);
		if (stat(path, &st) == 0)
		{
			free(address);
			address = NULL;
			address = _strdup(path);
			return (execve(address, args, NULL));
		}
		free(path);
		h++;
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
	int i, j, check, k = 0, l = 0;

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
