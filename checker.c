#include "main.h"

/**
 * checker - checks to see weather its a builts in function
 * @cmd: tokenized user input
 * @buf: line drived formgetline functions
 * Return: 1 if cmd exucted 0 if cmd is not executed
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
