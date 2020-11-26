#include "shell.h"

/**
 * floop - keeps the loop of prompt
 * @envp: environment
 * Return: 0
 */

int floop(char *envp[])
{
	char *line;
	char **args;
	int status;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		line = read_line();
		args = split_line(line);
		status = execute(line, args, envp);
		if (cmp(line) == 99)
		{
			free(line);
			free(args);
			return (127);
		}
		free(line);
		free(args);
	} while (status == 1);
	return (0);
}
