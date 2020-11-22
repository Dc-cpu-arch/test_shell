#include "shell.h"

/**
 *
 *
 */

int cmp(char *line)
{

	if (line[strlen(line + 1)] == '\n')
		line[strlen(line + 1)] = '\0';

	if (_strcmp(line, "exit") == 0)
	{
		return (99);
	}
	if (_strcmp(line, "env") == 0)
		return(0);
	else
		return(1);
}
