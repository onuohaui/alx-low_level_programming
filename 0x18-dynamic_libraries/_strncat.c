#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src.
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to use from src
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
