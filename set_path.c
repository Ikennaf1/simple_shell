#include "shell.h"

/**
 * set_path - Arranges and sets the path
 * @path: Given path
 * @args: Given arguments
 * @buf: The buffer
 * Return: Nothing
 */
void set_path(char *path, char **args, char *buf)
{
	char exec_path[] = "/bin/", *temp_args, *s, *tok[32], *str;
	int n = 0, i = 0, j = 0, k = 0, l = 0, flag = 0;

	if (args == NULL)
		return;
	
	temp_args = _strdup(args[0]);

	s = strtok(temp_args, "/");

	for (n = 0; s != NULL; n++)
	{
		tok[n] = s;
		s = strtok(NULL, "/");
	}

	for (i = 0; exec_path[i] != '\0'; i++)
		path[i] = exec_path[i];

	if (_strcmp(tok[0], "bin") != 0)
	{
		for (j = 0; args[0][j] != '\0'; i++, j++)
			path[i] = args[0][j];
	}
	else
	{
		str = (char *) malloc(1024 * sizeof(char));
		if (str == NULL)
			return;
		for (k = 5, l = 0; buf[k] != '\0'; k++, l++, i++)
		{
			if (flag == 0 && buf[k] == ' ')
				flag = 1;
			str[l] = buf[k];
			if (flag != 0)
				continue;
			path[i] = buf[k];
		}
		str[l] = '\0';
		free(buf);
		buf = _strdup(str);
		free(str);
	}
	path[i] = '\0';
	free(temp_args);
}
