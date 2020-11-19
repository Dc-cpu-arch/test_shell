#include "shell.h"
#define BUFFER 1024

int main(void)
{
	ssize_t bytes_of_char;
	size_t num_of_bytes = 0;
	char *sstr = malloc(sizeof(char) * BUFFER);
	char *arg[1];
	arg[0] = sstr;
	arg[1] = NULL;
	char pat[BUFFER] = "/bin/";

	bytes_of_char = getline(&sstr, &num_of_bytes, stdin);
	strcat(pat, sstr);
	printf ("pat: %s sstr: %s\n", pat, sstr);
	execv("/bin/ls", arg);
}
