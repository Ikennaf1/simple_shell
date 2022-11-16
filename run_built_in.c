#include "shell.h"

/**
 * run_built_in - Runs command if its built n
 * @cmd: Given command
 * @args: ...
 * @buf: ...
 * @path: ...
 * Return: Nothing
 */
void run_built_in(char *cmd, char **args, char *buf, char *path)
{
	if (is_built_in(cmd))
	{
		get_cmd_func(cmd);
	}
	free(args);
	free(buf);
	free(path);
	return;
}
