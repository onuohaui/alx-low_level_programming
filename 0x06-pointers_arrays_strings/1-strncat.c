#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The string to append to
 * @src: The string to append from
 * @n: The maximum number of bytes from src to append
 *
 * Return: A pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
