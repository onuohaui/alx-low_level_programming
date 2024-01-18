#include "main.h"

/**
 * _strncpy - copies a string, including the
 * terminating null byte, using at most n bytes from src.
 * @dest: destination buffer
 * @src: source string
 * @n: number of bytes to use from src
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
