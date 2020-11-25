#include "shell.h"

/**
 * floop - keeps the loop of prompt
 * @envp: environment
 */

void floop(char *envp[])
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
		free(line);
		free(args);
	} while (status == 1);
}
