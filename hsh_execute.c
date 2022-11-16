#include "shell.h"

/**
 * hsh_execute - Executes a command
 * @path: the path
 * @buf: the buffer
 * @args: ...
 * Return: 1 or 0
 */
int hsh_execute(char *path, char *buf, char **args)
{
	extern char **environ;
	int n;

	if (execve(path, hsh_split_cmd(buf), environ) == -1)
	{
		perror("./hsh");
		write(STDOUT_FILENO, "\n", 1);
	}
	free(path);
	free(buf);
	for (n = 0; args[n] != NULL; n++)
		free(args[n]);
	free(args);
	kill(getpid(), SIGINT);

	return (1);
}
