#include "shell.h"

/**
 * execBuiltInCommands - Executes a built-in command
 * @u_tokns: ...
 * @line: ...
 *
 * Return: 1 if is a built-in command or 0 if not
 */
int execBuiltInCommands(char **u_tokns, char *line)
{
	int i = 0, n = 0;
	char *ListBuiltinCmds[] = { "exit", "cd", "help", "env", NULL };

	while (ListBuiltinCmds[i])
	{
		if (_strcmp(u_tokns[0], ListBuiltinCmds[i]) == 0)
		{
			switch (i)
			{
				case 0:
					_handle_exit(u_tokns, line);
					break;
				case 1:
					chdir(u_tokns[1]);
					n = 1;
					break;
				case 2:
					_open_help();
					n = 1;
					break;
				case 3:
					_print_env();
					n = 1;
					break;
				default:
					break;
			}
			return (n);
		}
		i++;
	}

	return (0);
}
