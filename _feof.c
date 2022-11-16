#include "shell.h"

/**
 * _feof - Checks for EOF
 * @fd: File descriptor
 * Return: 1 if successful
 */
int _feof(int fd)
{
	if (fd == 0)
		return (1);
	else
		return (0);
}
