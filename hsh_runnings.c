#include "shell.h"

/**
 * hsh_runnings - The function that keeps the shell running
 * Return: Nothing
 */
void hsh_runnings(void)
{
	char *path, **args, *buf;
	pid_t pid;

	while (1)
	{
		path = (char *) malloc(1024 * sizeof(char));
		if (path == NULL)
			return;
		write(STDOUT_FILENO, "($) ", 4);
		buf = (char *) malloc(1024 * sizeof(char));
		if (buf == NULL)
			return;
		read_chars(buf);
		args = (char **) malloc(1024 * sizeof(char));
		if (args == NULL)
			return;
		args = hsh_split_cmd(buf);
		if (is_built_in(args[0]))
		{
			run_built_in(args[0], args, buf, path);
			continue;
		}
		set_path(path, args, buf);
		if (cmd_exists(path) == 0)
		{
			free(path);
			free(buf);
			free(args);
			continue;
		}
		pid = fork();
		if (pid < 0)
			return;
		if (pid == 0)
			hsh_execute(path, buf, args);
		else
			wait(NULL);
		write(STDOUT_FILENO, "\n", 1);
		fflush(stdout);
	}
}
