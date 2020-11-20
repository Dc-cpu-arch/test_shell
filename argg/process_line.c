#include "shell.h"
#define BUFSZ 64
#define DELIM " \t\r\n\a"

/**
 *
 *
 */

char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsz = 0;

	if (getline(&line, &bufsz, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
 *
 *
 *
 */

char **split_line(char *line)
{
	int bufsz = BUFSZ;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens) {
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL) {
		tokens[i] = token;
		i++;

		if (i >= bufsz) {
			bufsz += BUFSZ;
			tokens = realloc(tokens, bufsz * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "Error allocating memory\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
