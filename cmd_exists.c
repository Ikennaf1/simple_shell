#include "shell.h"

/**
 * cmd_exists - Checks if command exists
 * @cmd: The given command
 * Return: -1, 1 or 0
 */
int cmd_exists(char *cmd)
{
	char *cmd_split;
	char *s;
	char *new_cmd;
	char *tok[32];
	int n = 0;

	if (cmd == NULL)
		return (0);
	if (is_built_in(cmd))
		return (1);

	s = _strdup(cmd);

	cmd_split = strtok(s, " /");
	
	if (_strcmp(cmd_split, "bin") == 0)
	{
		while (cmd_split != NULL)
		{
			tok[n] = cmd_split;
			n++;
			cmd_split = strtok(NULL, " /");
		}
		new_cmd = tok[1];
	}
	else
	{
		new_cmd = cmd_split;
	}

	printf("%s\n", new_cmd);
	if (file_exists(new_cmd, "/bin/"))
		return (1);

	free(s);
	return (0);
}
