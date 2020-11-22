#include "shell.h"

/**
 *
 *
 */

int cmp(char *line, char * envp[])
{
	int i = 0;

	if (line[strlen(line + 1)] == '\n')
		line[strlen(line + 1)] = '\0';

	if (_strcmp(line, "exit") == 0)
	{
		printf("COMPARE LINE %s\n", line);
		printf("you typed exit\n");
		exit(0);
	}
	if (_strcmp(line, "env") == 0)
	{
		for (i = 0; envp[i] != NULL; i++)
		{
			printf("\n%s", envp[i]);
			//write(STDOUT_FILENO, envp[i], strlen(envp[i]));
			//write(STDOUT_FILENO, "\n", strlen(envp[i]));
		}
		putchar('\n');
		return(0);
	}
	return(-1);
}
