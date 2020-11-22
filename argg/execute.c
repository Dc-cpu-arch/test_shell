#include "shell.h"

int execute(char *line, char **args, char * envp[])
{
	//pid_t my_pid;
	pid_t pid;
	int status;
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
		return(0);
	}
	else if (pid == 0)
	{
		printf ("line is %s\n", line);
		if ((execv(line, args) == -1))
		{
			if (cmp(line, envp) == -1)
			{
			perror("Does not execute, write valid command");
			free(line);
			free(args);
			return(0);
			}
		}
	}
	return(1);
}
