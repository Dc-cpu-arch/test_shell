#include "shell.h"

/**
 *
 *
 */
int path(char *line, char **args)
{
	char *copy, *tokens, *tmp, *command, *tmpp;
	char *path, *address;
	char tmp2[1] = "/";
	int i = 0;
	//char *tokens2;

	struct stat st;

	copy = _getenv("PATH", environ);
	printf("COPY: %s\n", copy);
	tmp = _strdup(line);
	address = _strdup(line);
	tokens = strtok(copy, "PATH=");
	printf("ANTES DE QUITAR DOS PUNTOS\n COPY: %s\n TOKENS %s\n", copy, tokens);
	tmpp = _strdup(tokens);
	tokens = strtok(tmpp, ":");
	printf("DESPUES DE QUITAR DOS PUNTOS\n COPY: %s\n TOKENS %s\n\n", tmpp, tokens);
	command = strcat(tmp2, tmp);

	//for (i = 0; tokens2 != NULL; i++)
	while (tokens)
	{
		path = _strcat(tokens, command);
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
		i++;
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

/**
 *
 *
 *
 *
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
