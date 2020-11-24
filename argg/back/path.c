#include "shell.h"

/**
 *
 *
 */
char *path(char *line)
{
	struct stat st;
	char *copy, *tokens, *command;
	char *path, *address;
	int i;

	copy = _getpath();
	command = _strcat("/", line);
	address = _strdup(line);
	tokens = strtok(copy, ":");

	for (i = 0; tokens != NULL; i++)
	{
		path = _strcat(tokens, command);
		if (stat(path, &st) == 0)
		{
			free(address);
			address = NULL;
			address = _strdup(path);
		}
		tokens = strtok(NULL, ":");
		free(path);
		path = NULL;
	}
	free(copy);
	copy = NULL;
	free(command);
	command = NULL;
	return (address);
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
