#include "shell.h"

int execute(char *line, char **args, char * envp[])
{
	pid_t pid;
	int status;
	pid = fork();
	unsigned int i = 0, length;

	if (pid > 0)
	{
		wait(&status);
	}
	else if (pid == -1)
	{
		perror("Error:");
		free(line);
		free(args);
		return(0);
	}
	else
	{
		if ((execve(line, args, NULL) == -1))
		{
			if (cmp(line) == 0)
			{
				while (envp[i])
				{
					length = _strlen(envp[i]);
					write(STDOUT_FILENO, envp[i], length);
					write(STDOUT_FILENO, "\n", 1);
					++i;
				}
				return(0);
			}
			else if (cmp(line) == 1)
			{
				perror("Does not execute, write valid command");
				return(0);
			}
		}
	}
	return(1);
}
