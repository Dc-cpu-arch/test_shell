include "shell.h"

/**
 *
 *
 *
 */
char *_strcat(char *dest, char *src)
{
	int i;

	for (i = 0; dest[i] != '\0'; i++)

	for (i = i; *src; i++)
		*(dest + i) = *src++;

	return (dest);
}

/*
 *
 *
 *
 *
 */
int _strlen(char *s)
{
	int bytes;

	for (bytes = 0; *(s + bytes) != '\0'; bytes++)

	return (bytes);
}

/*
 *
 *
 *
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (-1);
	return (0);
}
