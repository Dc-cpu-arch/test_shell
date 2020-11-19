#include "shell.h"
#define BUFFER 1024

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
	char *sstr = malloc(sizeof(char) * BUFFER);
	pid_t child;
	char *arg[] = {sstr, NULL};
	char pat[BUFFER] = "/bin/";

	while (sstr)
	{
		printf("$ ");
		bytes_of_char = getline(&sstr, &num_of_bytes, stdin);

		if (bytes_of_char <= 1)
		{
			puts("You need to enter something");
		}
		if (sstr[bytes_of_char - 1] == '\n')
			sstr[bytes_of_char - 1] = '\0';

		if (strcmp(sstr, "exit") == 0)
		{
			puts("you typed exit!");
			return (1);
		}

		if (sstr)
		{
			child = fork();
			if (child == 0)
			{
				strcat(pat, sstr);
				//ir al directorio /bin/"command"
				//kill (child, SIGKILL);
				execv(pat, arg);
				printf("\n");
			}
		}
		else
		{
			printf("%s command not found\n", sstr);
		}
	}
	return (0);
}
