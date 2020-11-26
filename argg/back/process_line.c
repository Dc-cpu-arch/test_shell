#include "shell.h"
#define BUFSZ 64
#define DELIM " \t\r\n\a"

/**
 * read_line - read the user input
 * Return: line.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsz = 0;

	if (getline(&line, &bufsz, stdin) == EOF && isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	return (line);
}

/**
 * split_line - Split the args passed
 * @line: input of user
 * Return: tokens or exit_failure
 */
char **split_line(char *line)
{
	int bufsz = BUFSZ;
	int i = 0;
	char **tokens = malloc(bufsz * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsz)
		{
			bufsz += BUFSZ;
			tokens = NULL;
			tokens = malloc(bufsz * sizeof(char *));
			if (!tokens)
			{
				perror("Error allocating memory");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
