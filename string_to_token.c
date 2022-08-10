#include "main.h"

/**
 * nbr_spaces - return the number of space in string
 * @s: string to check
 * Return: number of spaces
 */
unsigned int nbr_spaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cmpt++;
	}
	return (cmpt);
}

/**
 * string_to_token - split into multiple words
 * @str: the string passed as argument
 * Return: token
 */
char **stringToTokens(char *str)
{
	int i = 0;
	const char separator[] = " ";
	int spaces = nbr_spaces(str);
	char **tokens = malloc(sizeof(char *) * (spaces + 1));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}
	token = strtok(str, separator);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
