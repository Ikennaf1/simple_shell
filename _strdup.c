#include "shell.h"

/**
 * _strlen - counts the chars
 * @s: the string
 * Return: Total
 */
unsigned int _strlen(char *s)
{
	unsigned int count = 0;

	while (*s)
	{
		count++;
		s++;
	}

	return (count);
}

/**
 * _strdup - returns a pointer to a new string
 * @str: The string
 * Return: Pointer to the new string
 */
char *_strdup(char *str)
{
	char *p;
	unsigned int count;
	unsigned int string_length;

	if (str == NULL)
		return (NULL);

	string_length = _strlen(str);

	p = malloc(1 + (sizeof(char) * string_length));

	if (p == NULL)
	{
		free(p);
		return (NULL);
	}

	for (count = 0; count < string_length; count++, str++)
		p[count] = *str;

	return (p);
}
