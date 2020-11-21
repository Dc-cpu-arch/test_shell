#include "shell.h"

void enviromentShell(char **sstr)
{
	char **environ;
	int i = 0;
	if (_strcmp(sstr[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", strlen(environ[i]));
			i++;
		}
	}
}
