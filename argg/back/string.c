#include "shell.h"

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

/**
 *
 *
 *
 *
 */
int _strlen(char *s)
{
	int len = 0;
	int i;

	for (i=0; s[i] != 0; i++)
	{
		len++;
	}
	return(len);
}
//	int bytes;

//	for (bytes = 0; *(s + bytes) != '\0'; bytes++)

//	return (bytes);
//}

/**
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

/**
 *
 *
 *
 */

char *_strdup(char *str)
{
	int i, size;
	char *dest;

	if (str == 0)
	{
		return (NULL);
	}

	for (size = 0; str[size] != 0; size++)
	{}
	dest = malloc((size + 1) * sizeof(char));
	for (i = 0; i < size; i++)
		dest[i] = str[i];

	dest[i] = '\0';
	return (dest);
}
