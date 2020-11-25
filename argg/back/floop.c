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
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute(line, args, envp);
		free(line);
		free(args);
	} while (status == 1);
}
