#include "shell.h"
#define DELIM " \t\n"

/**
 * hsh_split_cmd - Splits a line
 * @cmd: the line
 * Return: Array of strings
 */
char **hsh_split_cmd(char *cmd)
{
	char *str;
	char **token;
	char *s;
	/*char *tok[32];*/
	int n = 0;
	char **tok = (char **) malloc(1024 * sizeof(char));

	if (tok == NULL)
		return (NULL);

	if (cmd == NULL)
		return (NULL);
	token = (char **) malloc(1024 * sizeof(char));

	str = _strdup(cmd);
	s = strtok(str, DELIM);
	for (n = 0; s != NULL; n++)
	{
		tok[n] = s;
		s = strtok(NULL, DELIM);
	}
	tok[n] = (char *) NULL;
	token = tok;
	free(str);

	return (token);
}
