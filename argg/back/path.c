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
	char *path, *address, tmp2[1] = "/", *list[1024];
	int j;
	struct stat st;

	copy = _getenv("PATH", environ);
	tmp = _strdup(line);
	tokens = strtok(copy, "PATH=");
	tmpp = _strdup(tokens);
	list[0] = strtok(tmpp, ":");
	//command = _strcat(tmp2, tmp);
	j = 1;
	while (tokens)
	{
		tokens = strtok(NULL, ":");
		list[j] = tokens;
		j++;
	}
	j = 0;
	for (; list[j]; j++)
	{
		tmpp = _strdup(list[j]);
		command = _strcat(tmp2, tmp);
		path = _strcat(tmpp, command);
		printf("PATH IS %s\n", path);
		if (stat(path, &st) == 0)
		{
			printf("funciona?\n");
			free(address);
			address = NULL;
			address = _strdup(path);
			return (execve(address, args, NULL));
		}
		else
		{
			printf("gheey");
			free(tmpp);
			free(path);
		}
	}
	free (address);
	free(copy);
	copy = NULL;
	free(command);
	command = NULL;
	printf("HELLO\n");
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
