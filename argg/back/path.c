#include "shell.h"

/**
 *
 *
 */
char *path(char *line)
{
	struct stat st;
	char *copy, *tokens, *command;
	char *path, *addres;
	int i;

	copy = _getpath();
	command = str_concat("/", line);
	addres = _strdup(line);
	token = strtok(copy, ":");

	for (i = 0; token != NULL; i++)
	{
		path = str_concat(token, command);
		if (stat(path, &st) == 0)
		{
			free(addres);
			addres = NULL;
			adress = _strdup(path);
		}
		token = strtok(NULL, ":");
		free(path);
		path = NULL;
	}
	free(copy);
	copy = NULL;
	free(command);
	command = NULL;
	retrun (addres)
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
