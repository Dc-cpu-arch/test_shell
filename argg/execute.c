#include "shell.h"

int execute(char *line, char **args, char * envp[])
{
	pid_t pid;
	int status;
	pid = fork();
	int i = 0;

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
		if ((execv(line, args) == -1))
		{
			if (cmp(line) == 1)
			{
				perror("Does not execute, write valid command");
				free(line);
				free(args);
				return(0);
			}
			else if (cmp(line) == 0)
			{
				for (i = 0; envp[i] != NULL; i++)
				{
					printf("%s\n", envp[i]);
				}
				free (line);
				free(args);
				return(0);
			}
		}
	}
	return(1);
}
