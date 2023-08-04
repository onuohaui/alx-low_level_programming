#include "main.h"

/**
 * _atoi - Convert a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */

int _atoi(char *s)
{
	int sign = 1;
	int res = 0;
	int i = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	for (; s[i] != '\0'; ++i)
	{
		res = res * 10 + s[i] - '0';
	}

	return (sign * res);
}
