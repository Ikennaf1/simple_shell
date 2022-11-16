#include "shell.h"

/**
 * env - Displays the working environment
 */
int env(void)
{
	int n = 0;

	for (n = 0; environ[n] != NULL; n++)
	{
		write(STDOUT_FILENO, environ[n], _strlen(environ[n]));
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
