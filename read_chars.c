#include "shell.h"

/**
 * read_chars - Reads the characters entered
 * @buf: The buffer
 * Return: Num of chars read
 */
int read_chars(char *buf)
{
	int chars_read;

	chars_read = read(STDIN_FILENO, buf, 1024);
	if (_feof(chars_read))
	{
		free(buf);
		kill(getpid(), SIGINT);
		exit(EXIT_SUCCESS);
	}
	return (chars_read);
}
