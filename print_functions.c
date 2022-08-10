#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: 1 success, -1 error and errorno
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - prints a string
 * @s: string to input
 * Return: number of characters printed
 */
int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
