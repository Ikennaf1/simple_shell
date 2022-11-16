#include "shell.h"

/**
 * get_cmd_func - Find the cmds
 * @cmd: Supplied command
 *
 * Return: int
 */
int get_cmd_func(char *cmd)
{
	bi_t built_ins[] = {
		{"env", env},
		{"exit", _exit_},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(cmd, built_ins[i].cmd) == 0)
		{
			return (built_ins[i].func());
		}
		i++;
	}
	return (0);
}
