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

	while (sstr)
	{
		printf("$ ");
		bytes_of_char = getline(&sstr, &num_of_bytes, stdin);

		if (sstr[bytes_of_char - 1] == '\n')
			sstr[bytes_of_char - 1] = '\0';

		if (strcmp(sstr, "exit") == 0)
		{
			puts("you typed exit!");
			free(sstr);
			return (1);
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
