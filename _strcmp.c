#include "shell.h"

/**
 * _strcmp - Compares 2 strings
 * @s1: String 1
 * @s2: String 2
 * Return: -1, 0, or 1
 */
int _strcmp(char *s1, char *s2)
{
	char *a, *b;
	int result = 0, max = 0, count_a = 0, count_b = 0;

	a = s1;
	b = s2;
	while (*a != '\0')
	{
		count_a++;
		a++;
	}
	while (*b != '\0')
	{
		count_b++;
		b++;
	}
	a = s1;
	b = s2;
	if (count_a > count_b)
		max = count_a;
	else
		max = count_b;

	while (max > 0)
	{
		if (*a == *b)
		{
			a++;
			b++;
			max--;
			continue;
		}
		else
		{
			result = *a - *b;
			break;
		}
	}
	return (result);
}
