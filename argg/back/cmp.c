#include "shell.h"

/**
 * cmp - "Compare the user input for exit or env"
 * @line: user input
 * Return: 99 for exit, 0 for env and 1 if none of those
 */

int cmp(char *line)
{

	if (line[_strlen(line + 1)] == '\n')
		line[_strlen(line + 1)] = '\0';

	if (_strcmp(line, "exit") == 0)
	{
		return (99);
	}
	if (_strcmp(line, "env") == 0)
		return (0);
	else
		return (1);
}
