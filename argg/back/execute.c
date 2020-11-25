#include "shell.h"

/**
 * execute - executes a command get from stdout.
 * @line: command line input.
 * @args: possible arguments .
 * @envp: environment variable.
 * Return: 0 if it's working, otherwise 1..
 */
int execute(char *line, char **args, char *envp[])
{
	pid_t pid;
	int status;
	unsigned int i = 0, length;

	pid = fork();

	if (pid > 0)
	{
		wait(&status);
	}
	else if (pid == -1)
	{
		perror("Error:");
		free(line);
		free(args);
		return (0);
	}
	else
	{
		if ((execve(line, args, NULL) == -1))
		{
			if (cmp(line) == 0)
			{
				for (; envp[i]; i++)
				{
					length = _strlen(envp[i]);
					write(STDOUT_FILENO, envp[i], length);
					write(STDOUT_FILENO, "\n", 1);
				}
				return (0);
			}
			else if (cmp(line) == 1)
			{
				path(line, args);
				perror("Does not execute, write valid command");
				return (0);
			}
		}
	}
	return (1);
}
