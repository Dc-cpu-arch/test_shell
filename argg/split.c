#include "shell.h"

char **split(char *sstr)
{
	int counter = 0, i = 0;
	char *first_clean;
	char *token;
	char **tokenized_string;
	char *Copy;
	Copy = strdup(sstr);
	first_clean = strtok(Copy, " \n\t");
	while (first_Clean != NULL)
	{
		first_clean = strtok(NULL, " \n\t");
		counter++;
	}
	free(Copy);
	space = malloc(sizeof(char *) * (counter + 1));
	token = strtok(sstr, " \n\t");
	while (token != NULL)
	{
		tokenized_string[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	tokenized_string[i] = NULL;
	return (tokenized_string);
}
