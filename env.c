#include "shell.h"

/**
 * env - Displays the working environment
 * Return: 0
 */
int env(void)
{
	/*
	int n = 0;

	for (n = 0; environ[n] != NULL; n++)
	{
		write(STDOUT_FILENO, environ[n], _strlen(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
	*/
	int n = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		if (j != 0)
			_putchar('\n');
		i++;
	}
	return (0);
}
