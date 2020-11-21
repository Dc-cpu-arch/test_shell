#include "shell.h"

void execute(char *path, char *args)
{
	pid_t my_pid;
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
		free(path);
		free(args);
		exit(0);
	}
	else if (pid == 0)
	{
		if ((execve(path[0], args, NULL) == -1))
		{
			perror("Does not execute, write valid command");
			free(path);
			free(args);
			exit(0);
		}
	}
}
