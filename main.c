#include "main.h"

/**
 * execute - excutes the command
 * @cmd: command to run
 *
 * Return: 0 on success -1 if cmd is exit and 1 any other error
 */
int execute(char **cmd)
{
	pid_t child_pid;
	int status;

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * main - entry point
 * @ac: number of arguments
 * @av: list of arguments
 * Return: Always 0, -1 on error
 */
int main(int ac, char **av)
{
	int response;
	char **tokens;
	size_t bufsize = BUFSIZ;
	int isPipe = 0;
	char *buffer;

	signal(SIGINT, get_sigint);

	if (ac >= 2)
	{
		if (execve(av[1], av, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("unable to allocate buffer");
		exit(1);
	}
	do {
		if (isatty(fileno(stdin)))
		{
			isPipe = 1;
			_puts("#cisfun$ ");
		}
		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = string_to_tokens(buffer);
		response = execute(tokens);
	} while (isPipe && response != -1);

	return (0);
}
