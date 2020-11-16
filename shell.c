#include "shell.h"

/**
 *
 *
 *
 *
 */

int main(void)
{
	ssize_t bytes_of_char;
	size_t num_of_bytes = 0;
	char *sstr = "entry";
	pid_t child;


	while (sstr)
	{
		printf("$ Process PID %d", getpid());
		bytes_of_char = getline(&sstr, &num_of_bytes, stdin);

		if (sstr[bytes_of_char - 1] == '\n')
			sstr[bytes_of_char - 1] = '\0';

		if (strcmp(sstr, "exit") == 0)
		{
			puts("you typed exit!");
			free(sstr);
			return (1);
		}

		if (strcmp(sstr, "command") == 0)
		{
			child = fork();
			//ir al directorio /bin/"command"
			if (child == 0)
			{
				printf("command Child Process # %d\n", getpid());
				kill (child, SIGKILL);
			}
		}

		if (bytes_of_char <= 1)
		{
			puts("You need to enter something");
			free(sstr);
			return (1);
		}
		else
		{
			printf("%s\n", sstr);
		}
	}
	free(sstr);
	return (0);
}
