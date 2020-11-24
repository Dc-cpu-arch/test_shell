#include "shell.h"

/**
 *
 *
 */
int path(char *line, char **args)
{
	char *copy, *tokens, *tmp, *tmp2, *command;
	char *path, *address;
	int i;

	struct stat st;

	copy = _getpath();
	printf("command");
	tmp = _strdup(line);
	tmp2 = "/";
	address = _strdup(line);
	tokens = strtok(copy, ":");
	command = strcat(tmp2, tmp);

	for (i = 0; tokens != NULL; i++)
	{
		path = _strcat(tokens, tmp2);
		printf("address is =%s\n path = %s\n command is %s\n", address, path, command);
		if (stat(path, &st) == 0)
		{
			printf("Esta linea se ejecuta en path\n");
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
