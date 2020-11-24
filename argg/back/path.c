#include "shell.h"

/**
 *
 *
 */
int path(char *line, char **args)
{
	char *copy, *tokens, *tmp, *command;
	char *path, *address;
	char tmp2[1] = "/";
	//int i;
	char *tokens2;

	struct stat st;

	copy = _getpath();
	tmp = _strdup(line);
	address = _strdup(line);
	tokens = strtok(copy, "PATH=");
	tokens2 = strtok(tokens, ":");
	command = strcat(tmp2, tmp);

	printf("tokens = %s\n", tokens);
	//for (i = 0; tokens2 != NULL; i++)
	for (tokens2 = strtok(tokens, ":"); tokens2; tokens2 = strtok('\0', " "))
	{
		path = _strcat(tokens2, command);
		printf("address is =%s\n path = %s\n command is %s\n", address, path, command);
		if (stat(path, &st) == 0)
		{
			printf("Esta linea se ejecuta en path\n");
			free(address);
			address = NULL;
			address = _strdup(path);
			return (execve(address, args, NULL));
		}
		//printf("val of i is %d", i);
		//free(tokens2);
		//tokens = strtok(NULL, ":");
		free(path);
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
    char *copy = NULL;

    if (!environ || !*environ)
        return (NULL);

    for (i = 0; environ[i] != NULL; i++)
    {
	if (strncmp(environ[index], "PATH=", 5) == 0)
	{
		copy = strdup(environ[i]);
		return (copy);
	}
    }
    return (NULL);
}
