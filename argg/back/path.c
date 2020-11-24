#include "shell.h"

/**
 *
 *
 */
int path(char *line, char **args)
{
	char *copy, *tokens, *command;
	char *path, *address;
	int i;

	struct stat st;

	copy = _getpath();
	command = _strcat(line, "/");
	address = _strdup(line);
	tokens = strtok(copy, ":");

	for (i = 0; tokens != NULL; i++)
	{
		printf("Esta linea se ejecuta en path\n");
		path = _strcat(tokens, command);
		if (stat(path, &st) == 0)
		{
			free(address);
			address = NULL;
			address = _strdup(path);
			return (execve(address, args, NULL));
		}
		free(tokens);
		tokens = strtok(NULL, ":");
		free(path);
		path = NULL;
	}
	free(copy);
	copy = NULL;
	free(command);
	command = NULL;
	return (-1);
}

/**
 *
 *
 *
 */
char *_getpath(void)
{
    int index = 0;

    if (!environ || !*environ)
        return (NULL);

    while (strncmp(environ[index], "PATH=", 5))
        index++;

    return (environ[index]);
}
