#include "main.h"

/**
 * _putchar - writes character to stdout
 * @c: the character to print
 *
 * Return: 1 for success, -1 for error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
