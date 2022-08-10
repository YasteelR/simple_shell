#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: input one
 * @s2: input two
 * Return: retrurns diffrence b/n strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;
	output = (*(s1 + i) - *(s2 + i));
	return (output);
}

/**
 * _strlen - returns the length of the string
 * @s: string input
 * Return: returns length of string passed
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strncmp - compares two string pu to n bytes
 * @s1: compared to s2
 * @s2: compared to s1
 * @n: number of bytes
 * Return: diffrence between s1 and s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - duplicates string
 * @s: input to udplicate
 * Return: pointer to duplicate string
 */
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);

	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];
	ptr[i++] = '\0';
	return (ptr);
}

/**
 * _strchr - locates a character in a string
 * @s: string to check
 * @c: character to be loacted
 * Return: return pointer to first occurence of character
 * or NULL if character not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
