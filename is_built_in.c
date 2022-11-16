#include "shell.h"

/**
 * is_built_in - Checks if command is built in
 * @cmd: Given command
 * Return: 1 or 0
 */
int is_built_in(char *cmd)
{
	char *built_ins[3] = {
		"exit",
		"env",
		NULL
	};
	int x = 0;

	for (x = 0; built_ins[x] != NULL; x++)
	{
		if (_strcmp(cmd, built_ins[x]) == 0)
			return (1);
	}
	return (0);
}
