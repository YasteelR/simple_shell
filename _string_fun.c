#include "main.h"

/**
 * _strlen - find the length of a string
 * @s: string pointer intput
 * Return: number of characters
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

