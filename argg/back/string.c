#include "shell.h"

/**
 * _strtok - function that tokenize a string like strtok.
 * @s: string.
 * @delm: delimiter.
 * Return: string tokenized.
 */
char **_strtok(char *s, char *delm)
{
	static int currIndex;
	char **W;
	int i = currIndex, k = 0, j = 0;

	if (!s || !delm || s[currIndex] == '\0')
		return (NULL);

	W = (char **)malloc(sizeof(char) * 100);

	while (s[i] != '\0')
	{
		j = 0;
		while (delm[j] != '\0')
		{
			if (s[i] != delm[j])
				W[k] = &s[i];
			else
				goto It;
			j++;
		}

		i++;
		k++;
	}
It:
	W[i] = 0;
	currIndex = i + 1;
	return (W);
}

/**
 * _strcat - Function that concatenate two strings like strcat.
 * @dest: destination string.
 * @src: source string.
 * Return: destination string with the source concatenated.
 */
char *_strcat(char *dest, char *src)
{

	int i = 0;
	int r = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[r])
	{
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - Function that calculates de length of a string.
 * @s: string.
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int len = 0;
	int i;

	for (i = 0; s[i] != 0; i++)
	{
		len++;
	}

	return (len);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: string 1.
 * @s2: string 2.
 * Return: 0 if string 1 is equal to string 2, -1 if not.
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
 * _strdup - Function that duplicate a string.
 * @str: string to duplicate.
 * Return: NULL if string is 0, in success return the duplication.
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
	for (i = 0; i <= size; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
