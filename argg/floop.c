#include "shell.h"

/**
 *
 *
 *
 */

void floop(void)
{
	char *line;
	//char **args;
	int status;
	int i = 6;

	do {
		printf("$ ");
		line = read_line();
		//args = split_line();
		//status = executee(args);

		free(line);
		//free(args);
	} while (i == 6);
}
