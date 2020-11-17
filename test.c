#include "shell.h"

int main(void)
{
	char sstr[100] = "ls";
	char *arg[1];
	arg[0] = sstr;
	arg[1] = NULL;
	char pat[100] = "/bin/";

	printf("Before strcat, pat: %s and sstr: %s\n", pat,sstr);

	printf ("pat: %s sstr: %s\n", pat, sstr);
	execv(pat, arg);
}
