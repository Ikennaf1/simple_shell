#include "shell.h"

/**
 * _exit_ - Exits the shell
 * Return: 0
 */
int _exit_(void)
{
	kill(getpid(), SIGINT);
	return (0);
}
