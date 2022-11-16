#include "shell.h"

/**
 * _strcat - Concatenates 2 strings
 * @dest: The final string
 * @src: The second string
 * Return: Pointer to the final string
 */
char *_strcat(char *dest, char *src)
{
	char *p;

	p = dest;

	while (*p != '\0')
		p++;

	while (*src != '\0')
	{
		*p = *src;
		p++;
		src++;
	}

	*p = '\0';

	return (dest);
}
