#include "shell.h"
#define BUFF 1024

/**
 *
 *
 *
 *
 */

int main (void)
{
	ssize_t bytes_of_char;
	size_t num_of_bytes = 0;
	char *sstr = NULL;

	printf("$ ");
	bytes_of_char = getline(&sstr, &num_of_bytes, stdin);

	if (bytes_of_char <= 0)
	{
		puts ("You need to enter something");
		return (1);
	}
	else
		printf("%s", sstr);

	free (sstr);

	return (0);
}
