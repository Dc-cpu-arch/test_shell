#include "shell.h"

/**
 * path - gets the appropriate directory for a given command from stdout.
 * @line: command line user input.
 * @args: possible arguments.
 * Return: the execution of the given command, otherwise -1.
 */

int path(char *line, char **args)
{
	char *copy, *tokens, *tmp, *command, *tmpp;
	char *path, *address, tmp2[1] = "/", *list[1024];
	int j = 1;
	struct stat st;

	copy = _getenv("PATH", environ);
	tmp = _strdup(line);
	tokens = strtok(copy, "PATH=");
	tmpp = _strdup(tokens);
	list[0] = strtok(tmpp, ":");
	while (tokens)
	{
		tokens = strtok(NULL, ":");
		list[j] = tokens;
		j++;
	}

	for (j = 0; j < 5; j++)
	{
		tmpp = _strdup(list[j]);
		//command = _strcat(tmp2, tmp);
		//path = _strcat(tmpp, command);
		_strcat(tmp2, tmp);
		_strcat(tmpp, tmp2);
		printf("TMPP IS %s\n", tmpp);
		if (stat(tmpp, &st) == 0)
		{
			printf("FUNCIONA\n");
			address = NULL;
			address = _strdup(tmpp);
			return (execve(address, args, NULL));
		}
		printf("asdfasdfasdf\n");
		free(tmpp);
		free(path);
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
