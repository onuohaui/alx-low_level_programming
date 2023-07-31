#include "main.h"

/**
 * _memset - fill memory with a constant byte
 * @s: pointer to the memory area to fill
 * @b: constant byte to fill memory with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
